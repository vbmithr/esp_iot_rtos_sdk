/* 
 * copyright (c) Espressif System 2010
 * 
 */

#ifndef __SPI_FLASH_H__
#define __SPI_FLASH_H__

#include <stddef.h>
#include <stdint.h>

typedef enum {
    SPI_FLASH_RESULT_OK,
    SPI_FLASH_RESULT_ERR,
    SPI_FLASH_RESULT_TIMEOUT
} SpiFlashOpResult;

#define SPI_FLASH_SEC_SIZE      4096

SpiFlashOpResult spi_flash_erase_sector(int sec);
SpiFlashOpResult spi_flash_write(uint32_t des_addr, uint32_t *src_addr, size_t size);
SpiFlashOpResult spi_flash_read(uint32_t src_addr, uint32_t *des_addr, size_t size);

#endif
