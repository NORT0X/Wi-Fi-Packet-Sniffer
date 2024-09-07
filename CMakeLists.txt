cmake_minimum_required(VERSION 3.10)
project(WifiPacketSniffer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for PCAP library
include_directories(${PROJECT_SOURCE_DIR}/inc)

find_path(PCAP_INCLUDE_DIR pcap.h)
find_package(Pcap REQUIRED)

if(PCAP_INCLUDE_DIR AND PCAP_LIBRARY)
    message(STATUS "Found PCAP library: ${PCAP_LIBRARY}")
    include_directories(${PCAP_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Could not find the PCAP library")
endif()

# Source files
set(SOURCE_FILES
    src/main.cpp
    src/packet_handler.cpp
    src/interface_selector.cpp
)

# Add the executable
add_executable(WifiPacketSniffer ${SOURCE_FILES})

# Link the libraries
target_link_libraries(WifiPacketSniffer pcap)

