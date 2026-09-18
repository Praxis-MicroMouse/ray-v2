#include "udp.h"

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

static WiFiUDP udp;

bool udp_init(void)
{
    WiFi.begin(UDP_SSID, UDP_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
        delay(100);

    return udp.begin(UDP_PORT);
}

void udp_send(const char *message)
{
    udp.beginPacket("10.105.76.236", UDP_PORT);
    udp.print(message);
    udp.endPacket();
}

bool udp_receive(char *buffer, uint16_t size)
{
    int len = udp.parsePacket();

    if (!len)
        return false;

    len = udp.read(buffer, size - 1);
    buffer[len] = '\0';

    return true;
}