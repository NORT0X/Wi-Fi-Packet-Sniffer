#include "interface_selector.hpp"
#include <iostream>
#include <vector>

void listInterfaces(pcap_if_t *alldevs)
{
    int i = 0;
    pcap_if_t *d;
    for (d = alldevs; d; d = d->next)
    {
        std::cout << ++i << ": " << d->name << " - " << (d->description ? d->description : "No description available") << std::endl;
    }
}

pcap_if_t *selectInterface(pcap_if_t *alldevs)
{
    listInterfaces(alldevs);

    int choice;
    std::cout << "Enter the number of the device to use: ";
    std::cin >> choice;

    pcap_if_t *d = alldevs;
    for (int i = 1; i < choice && d; ++i)
    {
        d = d->next;
    }

    if (d == nullptr)
    {
        std::cerr << "Invalid choice." << std::endl;
        return nullptr;
    }

    return d;
}
