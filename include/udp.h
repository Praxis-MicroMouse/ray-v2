#ifndef UDP_H
#define UDP_H

#include <stdint.h>
#include <stdbool.h>

#define UDP_SSID "Yasiru"
#define UDP_PASSWORD "hitler1889"
#define UDP_PORT 5000

bool udp_init(void);
void udp_send(const char *message);
bool udp_receive(char *buffer, uint16_t size);

#endif