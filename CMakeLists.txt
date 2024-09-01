cmake_minimum_required(VERSION 3.10)
project(WifiPacketSniffer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for PCAP library
include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories("C:/npcap/Include")

# Find the PCAP library
link_directories("C:/npcap/Lib/x64")

# Source files
set(SOURCE_FILES
    src/main.cpp
    src/packet_handler.cpp
    src/interface_selector.cpp
)

# Add the executable
add_executable(WifiPacketSniffer ${SOURCE_FILES})

# Link the libraries
target_link_libraries(WifiPacketSniffer wpcap Packet)

