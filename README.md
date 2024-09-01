# Wi-Fi-Packet-Sniffer

The Wi-Fi Packet Sniffer is a network monitoring tool that uses Npcap to capture and analyze network packets on a specified interface.

## Prerequisites

- Npcap: This tool requires the Npcap library to be installed. You can download it from [Npcap&apos;s official site](https://npcap.com/).

- CMake: Used for managing the build process.

- Compiler: Ensure you have a compatible C++ compiler installed (e.g., MinGW).

## How to run

In the root folder run:
```
cmake -G "Unix Makefiles" -S . -B build
```

And after that:
```
cd build
make
```

Inside build directory run WifiPacketSniffer.exe
