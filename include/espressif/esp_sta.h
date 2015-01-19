/*
 *  Copyright (C) 2013 -2014  Espressif System
 *
 */

#ifndef __ESP_STA_H__
#define __ESP_STA_H__

#include <stdint.h>

#include "queue.h"

struct station_config {
    char ssid[32];
    char password[64];
    uint8_t bssid_set;
    char bssid[6];
};

int wifi_station_get_config(struct station_config *config);
int wifi_station_set_config(struct station_config *config);

int wifi_station_connect(void);
int wifi_station_disconnect(void);

struct scan_config {
    char *ssid;
    char *bssid;
    uint8_t channel;
    uint8_t show_hidden;
};

struct bss_info {
    STAILQ_ENTRY(bss_info)     next;

    char bssid[6];
    char ssid[32];
    uint8_t channel;
    int8_t rssi;
    uint8_t authmode;
    uint8_t is_hidden;
};

typedef enum {
    STATUS_OK = 0,
    STATUS_FAIL,
    STATUS_PENDING,
    STATUS_BUSY,
    STATUS_CANCEL,
} status_t;

typedef void (* scan_done_cb_t)(void *arg, status_t status);

int wifi_station_scan(struct scan_config *config, scan_done_cb_t cb);

int wifi_station_get_auto_connect(void);
int wifi_station_set_auto_connect(int set);

enum {
    STATION_IDLE = 0,
    STATION_CONNECTING,
    STATION_WRONG_PASSWORD,
    STATION_NO_AP_FOUND,
    STATION_CONNECT_FAIL,
    STATION_GOT_IP
};

int wifi_station_get_connect_status(void);

#endif
