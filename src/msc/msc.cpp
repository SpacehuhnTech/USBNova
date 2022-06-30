/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "msc.h"

#include "SPI.h"
#include "Adafruit_SPIFlash.h"
#include "Adafruit_TinyUSB.h"

namespace msc {
    // ===== PRIVATE ===== //
    Adafruit_FlashTransport_SPI flashTransport(EXTERNAL_FLASH_USE_CS, EXTERNAL_FLASH_USE_SPI);
    Adafruit_SPIFlash flash(&flashTransport);
    Adafruit_USBD_MSC usb_msc;

    FatFileSystem fatfs;
    FatFile file;
    
    bool fs_changed = false; // Flag which goes to true when PC write to flash

    // Callback invoked when received READ10 command.
    // Copy disk's data to buffer (up to bufsize) and
    // return number of copied bytes (must be multiple of block size)
    int32_t read_cb(uint32_t lba, void *buffer, uint32_t bufsize) {
        // Note: SPIFLash Block API: readBlocks/writeBlocks/syncBlocks
        // already include 4K sector caching internally. We don't need to cache it, yahhhh!!
        return flash.readBlocks(lba, (uint8_t *)buffer, bufsize / 512) ? bufsize : -1;
    }

    // Callback invoked when received WRITE10 command.
    // Process data in buffer to disk's storage and
    // return number of written bytes (must be multiple of block size)
    int32_t write_cb(uint32_t lba, uint8_t *buffer, uint32_t bufsize)
    {
        digitalWrite(LED_BUILTIN, HIGH);

        // Note: SPIFLash Block API: readBlocks/writeBlocks/syncBlocks
        // already include 4K sector caching internally. We don't need to cache it, yahhhh!!
        return flash.writeBlocks(lba, buffer, bufsize / 512) ? bufsize : -1;
    }

    // Callback invoked when WRITE10 command is completed (status received and accepted by host).
    // used to flush any pending cache.
    void flush_cb(void)
    {
        // sync with flash
        flash.syncBlocks();

        // clear file system's cache to force refresh
        fatfs.cacheClear();

        fs_changed = true;

        digitalWrite(LED_BUILTIN, LOW);
    }
    
    // ===== PUBLIC ===== //
    void init() {
        flash.begin();

        usb_msc.setID("Adafruit", "External Flash", "1.0"); // Max. 8, 16, 4 characters
        usb_msc.setReadWriteCallback(read_cb, write_cb, flush_cb);
        usb_msc.setCapacity(flash.size() / 512, 512);
        usb_msc.setUnitReady(true);
        usb_msc.begin();

        fatfs.begin(&flash);
    }

    bool changed() {
        bool tmp = fs_changed;
        fs_changed = false;
        return tmp;
    }

    bool prepare_read(const char* path) {
        if (!path) return false;

        return file.open(path);
    }

    size_t read_line(char* buffer, size_t len) {
        size_t read { 0 };

        // Read as long as the file has data and buffer is not full
        // -1 to compensate for a extra linebreak at the end of the file
        while (file.available() && read < len-1) {
            // Read character by character
            char c = file.read();

            if (c == '\r') c = '\n';

            // Write into buffer
            buffer[read] = c;
            ++read;

            // If linebreak found, break loop
            if (c == '\n') {
                while (file.peek() == '\n') file.read();
                break;
            }
            // If no linebreak found, but file ended, add linebreak as last character
            else if (!file.available()) {
                buffer[read] = '\n';
                ++read;
            }
        }

        return read;

        // return file.readBytesUntil('\n', buffer, len);
    }
}