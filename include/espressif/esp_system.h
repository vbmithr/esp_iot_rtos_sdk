/*
 *  Copyright (C) 2013 -2014  Espressif System
 *
 */

#ifndef __ESP_SYSTEM_H__
#define __ESP_SYSTEM_H__

#include <stdint.h>

enum rst_reason {
    DEFAULT_RST_FLAG	= 0,
    WDT_RST_FLAG	= 1,
    EXP_RST_FLAG    = 2
};

struct rst_info {
	uint32_t flag;
	uint32_t exccause;
	uint32_t epc1;
	uint32_t epc2;
	uint32_t epc3;
	uint32_t excvaddr;
	uint32_t depc;
};

void system_restore(void);
void system_restart(void);
void system_deep_sleep(uint32_t time_in_us);

uint32_t system_get_time(void);

void system_print_meminfo(void);
uint32_t system_get_free_heap_size(void);
uint32_t system_get_chip_id(void);

uint32_t system_rtc_clock_cali_proc(void);
uint32_t system_get_rtc_time(void);

int system_rtc_mem_read(uint8_t src, void *dst, uint16_t n);
int system_rtc_mem_write(uint8_t dst, const void *src, uint16_t n);

void system_uart_swap(void);

#endif
