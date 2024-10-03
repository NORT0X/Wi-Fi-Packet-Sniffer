#include "packet_handler.hpp"
#include <iostream>
#include <iomanip>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>

void printPacketInfo(const u_char *packet, const struct pcap_pkthdr *pkthdr)
{
    const struct ether_header *ethHeader = reinterpret_cast<const struct ether_header *>(packet);
    const struct ip *ipHeader = reinterpret_cast<const struct ip *>(packet + sizeof(struct ether_header));

    std::cout << "Packet captured at: " << pkthdr->ts.tv_sec << " seconds, " << "Lenght: " << pkthdr->len << " bytes" << std::endl;

    std::cout << "Ethernet Header: " << std::endl;
    std::cout << "Source MAC: " << ether_ntoa(reinterpret_cast<const struct ether_addr *>(ethHeader->ether_shost)) << std::endl;
    std::cout << "Destination MAC: " << ether_ntoa(reinterpret_cast<const struct ether_addr *>(ethHeader->ether_dhost)) << std::endl;
    std::cout << "Protocol Type: " << ntohs(ethHeader->ether_type) << std::endl;

    if (ntohs(ethHeader->ether_type) == ETHERTYPE_IP)
    {
        std::cout << "IP Header:" << std::endl;
        std::cout << "Source IP: " << inet_ntoa(ipHeader->ip_src) << std::endl;
        std::cout << "Destination IP: " << inet_ntoa(ipHeader->ip_dst) << std::endl;
        std::cout << "Protocol: " << static_cast<int>(ipHeader->ip_p) << std::endl;

        if (ipHeader->ip_p == IPPROTO_TCP)
        {
            const struct tcphdr *tcpHeader = reinterpret_cast<const struct tcphdr *>(packet + sizeof(struct ether_header) + sizeof(struct ip));
            std::cout << "TCP Header:" << std::endl;
            std::cout << "Source Port: " << ntohs(tcpHeader->th_sport) << std::endl;
            std::cout << "Destination Port: " << ntohs(tcpHeader->th_dport) << std::endl;
        }
        else if (ipHeader->ip_p == IPPROTO_UDP)
        {
            const struct udphdr *udpHeader = reinterpret_cast<const struct udphdr *>(packet + sizeof(struct ether_header) + sizeof(struct ip));
            std::cout << "UDP Header:" << std::endl;
            std::cout << "Source Port: " << ntohs(udpHeader->uh_sport) << std::endl;
            std::cout << "Destination Port: " << ntohs(udpHeader->uh_dport) << std::endl;
        }
    }

    std::cout << "----------------------------------------------" << std::endl;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    printPacketInfo(packet, pkthdr);

    // Additional processing can be done here (e.g., parsing headers)
}
