#include "packet_handler.hpp"
#include <iostream>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    std::cout << "Packet captured at: " << pkthdr->ts.tv_sec << ", Length: " << pkthdr->len << std::endl;

    // Additional processing can be done here (e.g., parsing headers)
}
