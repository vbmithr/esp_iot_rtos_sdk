/*
 *  Copyright (C) 2013 -2014  Espressif System
 *
 */

#ifndef __ESP_SOFTAP_H__
#define __ESP_SOFTAP_H__

typedef enum _auth_mode {
    AUTH_OPEN           = 0,
    AUTH_WEP,
    AUTH_WPA_PSK,
    AUTH_WPA2_PSK,
    AUTH_WPA_WPA2_PSK
} AUTH_MODE;

struct softap_config {
    char ssid[32];
    char password[64];
    uint8_t ssid_len;
    uint8_t channel;
    uint8_t authmode;
    uint8_t ssid_hidden;
    uint8_t max_connection;
};

int wifi_softap_get_config(struct softap_config *config);
int wifi_softap_set_config(struct softap_config *config);

#endif
