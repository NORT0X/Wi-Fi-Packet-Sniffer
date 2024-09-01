#pragma once

#include <pcap.h>

void listInterfaces(pcap_if_t *alldevs);

pcap_if_t *selectInterface(pcap_if_t *alldevs);