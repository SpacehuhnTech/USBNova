/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "format.h"

#include "../../config.h"
#include "../../debug.h"

// This module is based on the Adafruit SPI Flash FatFs Format Example
// https://github.com/adafruit/Adafruit_SPIFlash/tree/master/examples/SdFat_format

#include <SPI.h>
#include <SdFat.h>
#include <Adafruit_SPIFlash.h>

// Since SdFat doesn't fully support FAT12 such as format a new flash
// We will use Elm Cham's fatfs f_mkfs() to format
#include "ff.h"
#include "diskio.h"

namespace format {
    // ========== PRIVATE ========= //
#if defined(ARDUINO_ARCH_RP2040)
    // RP2040 use same flash device that store code for file system. Therefore we
    // only need to specify start address and size (no need SPI or SS)
    // By default (start=0, size=0), values that match file system setting in
    // 'Tools->Flash Size' menu selection will be used.
    Adafruit_FlashTransport_RP2040 flashTransport;
#else // if defined(ARDUINO_ARCH_RP2040)
    Adafruit_FlashTransport_SPI flashTransport(EXTERNAL_FLASH_USE_CS, EXTERNAL_FLASH_USE_SPI);
#endif // if defined(ARDUINO_ARCH_RP2040)

    Adafruit_SPIFlash flash(&flashTransport);

    // file system object from SdFat
    FatFileSystem fatfs;

    // Elm Cham's fatfs objects
    FATFS   elmchamFatfs;
    uint8_t workbuf[4096]; // Working buffer for f_fdisk function.

    // --------------------------------------------------------------------+
    // fatfs diskio
    // --------------------------------------------------------------------+
    extern "C"
    {
        DSTATUS disk_status(BYTE pdrv) {
            (void)pdrv;
            return 0;
        }

        DSTATUS disk_initialize(BYTE pdrv) {
            (void)pdrv;
            return 0;
        }

        DRESULT disk_read(BYTE  pdrv,   /* Physical drive nmuber to identify the drive */
                          BYTE* buff,   /* Data buffer to store read data */
                          DWORD sector, /* Start sector in LBA */
                          UINT  count   /* Number of sectors to read */
                          ) {
            (void)pdrv;
            return flash.readBlocks(sector, buff, count) ? RES_OK : RES_ERROR;
        }

        DRESULT disk_write(BYTE        pdrv,   /* Physical drive nmuber to identify the drive */
                           const BYTE* buff,   /* Data to be written */
                           DWORD       sector, /* Start sector in LBA */
                           UINT        count   /* Number of sectors to write */
                           ) {
            (void)pdrv;
            return flash.writeBlocks(sector, buff, count) ? RES_OK : RES_ERROR;
        }

        DRESULT disk_ioctl(BYTE  pdrv, /* Physical drive nmuber (0..) */
                           BYTE  cmd,  /* Control code */
                           void* buff  /* Buffer to send/receive control data */
                           ) {
            (void)pdrv;

            switch (cmd) {
                case CTRL_SYNC:
                    flash.syncBlocks();
                    return RES_OK;

                case GET_SECTOR_COUNT:
                    *((DWORD*)buff) = flash.size()/512;
                    return RES_OK;

                case GET_SECTOR_SIZE:
                    *((WORD*)buff) = 512;
                    return RES_OK;

                case GET_BLOCK_SIZE:
                    *((DWORD*)buff) = 8; // erase block size in units of sector size
                    return RES_OK;

                default:
                    return RES_PARERR;
            }
        }
    }

    // ========== PUBLIC ========= //
    bool start(const char* drive_name) {
        debugln("Starting format...");

        // Initialize flash library and check its chip ID.
        if (!flash.begin()) {
            debugln("Error, failed to initialize flash chip!");
            return false;
        }

        debug("Flash chip JEDEC ID: 0x");
        debugln(flash.getJEDECID(), HEX);

        // Call fatfs begin and passed flash object to initialize file system
        debugln("Creating and formatting FAT filesystem (this takes ~60 seconds)...");

        // Make filesystem.
        FRESULT r = f_mkfs("", FM_FAT | FM_SFD, 0, workbuf, sizeof(workbuf));
        if (r != FR_OK) {
            debug("Error, f_mkfs failed with error code: ");
            debugln(r, DEC);
            return false;
        }

        // Mount to set disk label
        r = f_mount(&elmchamFatfs, "0:", 1);
        if (r != FR_OK) {
            debug("Error, f_mount failed with error code: ");
            debugln(r, DEC);
            return false;
        }

        // Setting label
        debug("Setting disk label to:");
        debugln(drive_name);
        r = f_setlabel(drive_name);
        if (r != FR_OK) {
            debug("Error, f_setlabel failed with error code: ");
            debugln(r, DEC);
            return false;
        }

        // unmount
        f_unmount("0:");

        // sync to make sure all data is written to flash
        flash.syncBlocks();

        debugln("Formatted flash!");

        // Check new filesystem
        if (!fatfs.begin(&flash)) {
            debugln("Error, failed to mount newly formatted filesystem!");
            return false;
        }

        // Done!
        debugln("Flash chip successfully formatted with new empty filesystem!");
        return true;
    }
}