// Try max SPI clock for an SD. Reduce SPI_CLOCK if errors occur.
#define SPI_CLOCK SD_SCK_MHZ(15)

#include <SdFat.h>

#if USE_CUSTOM_SPI_PINOUT
    #if  ENABLE_DEDICATED_SPI
        #define SD_CONFIG SdSpiConfig(SD_PIN_CS, DEDICATED_SPI, SPI_CLOCK, &SPI1)
    #else
        #define SD_CONFIG SdSpiConfig(SD_PIN_CS, SHARED_SPI, SPI_CLOCK, &SPI1)
    #endif
#else
    // Try to select the best SD card configuration.
    #if defined(HAS_SDIO_CLASS) && defined(SDIO_USE_PIO)
        #define SD_CONFIG SdioConfig(FIFO_SDIO)
    #elif  ENABLE_DEDICATED_SPI
        #define SD_CONFIG SdSpiConfig(SD_PIN_CS, DEDICATED_SPI, SPI_CLOCK)
    #else 
        #define SD_CONFIG SdSpiConfig(SD_PIN_CS, SHARED_SPI, SPI_CLOCK)
    #endif
#endif