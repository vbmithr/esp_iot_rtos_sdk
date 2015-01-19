/*
 *  Copyright (C) 2013 -2014  Espressif System
 *
 */

#ifndef __ESP_WIFI_H__
#define __ESP_WIFI_H__

#include <lwip/ip4_addr.h>

typedef enum opmode {
    NULL_MODE = 0,
    STATION_MODE,
    SOFTAP_MODE,
    STATIONAP_MODE,
    MAX_MODE
} opmode_t;

opmode_t wifi_get_opmode(void);
int wifi_set_opmode(opmode_t opmode);

typedef enum iface_idx {
    STATION_IF = 0,
    SOFTAP_IF
} iface_idx_t;

struct ip_info {
    struct ip_addr ip;
    struct ip_addr netmask;
    struct ip_addr gw;
};

int wifi_get_ip_info(iface_idx_t idx, struct ip_info *info);
int wifi_set_ip_info(iface_idx_t idx, struct ip_info *info);
int wifi_get_macaddr(iface_idx_t idx, char *macaddr);
int wifi_set_macaddr(iface_idx_t, char *macaddr);

int wifi_get_channel(void);
int wifi_set_channel(int channel);

int wifi_status_led_install(int gpio_id, int gpio_name, int gpio_func);

int wifi_promiscuous_enable(int promiscuous);

typedef void (* wifi_promiscuous_cb_t)(char *buf, int len);

void wifi_set_promiscuous_rx_cb(wifi_promiscuous_cb_t cb);

typedef enum phy_mode {
    PHY_MODE_11B = 1,
    PHY_MODE_11G,
    PHY_MODE_11N
} phy_mode_t;

phy_mode_t wifi_get_phy_mode(void);
int wifi_set_phy_mode(phy_mode_t mode);

#endif
