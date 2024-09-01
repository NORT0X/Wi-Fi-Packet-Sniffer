#include <iostream>
#include <pcap.h>
#include "packet_handler.hpp"
#include "interface_selector.hpp"

int main()
{
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Retrieve the device list
    if (pcap_findalldevs(&alldevs, errbuf) == -1)
    {
        std::cerr << "Error finding devices: " << errbuf << std::endl;
        return 1;
    }

    // Select an interface
    pcap_if_t *selected_device = selectInterface(alldevs);
    if (selected_device == nullptr)
    {
        pcap_freealldevs(alldevs);
        return 1;
    }

    std::cout << "Using device: " << selected_device->name << std::endl;

    // Open the selected device
    handle = pcap_open_live(selected_device->name, 65536, 1, 1000, errbuf);
    if (handle == nullptr)
    {
        std::cerr << "Could not open device " << selected_device->name << ": " << errbuf << std::endl;
        pcap_freealldevs(alldevs);
        return 1;
    }

    // Start packet capture loop
    pcap_loop(handle, 0, packetHandler, nullptr);

    // Clean up
    pcap_freealldevs(alldevs);
    pcap_close(handle);

    return 0;
}
