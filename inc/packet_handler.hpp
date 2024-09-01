#pragma once

#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet);