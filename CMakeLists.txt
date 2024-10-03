cmake_minimum_required(VERSION 3.10)
project(WifiPacketSniffer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for local headers
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Find PCAP library
find_package(PkgConfig)

if(PkgConfig_FOUND)
    pkg_check_modules(PCAP REQUIRED libpcap)
    include_directories(${PCAP_INCLUDE_DIRS})
else()
    # Manually find PCAP if pkg-config is not available
    find_path(PCAP_INCLUDE_DIR pcap.h PATHS /usr/include /usr/local/include)
    find_library(PCAP_LIBRARY NAMES pcap PATHS /usr/lib /usr/local/lib)

    if(PCAP_INCLUDE_DIR AND PCAP_LIBRARY)
        message(STATUS "Found PCAP library: ${PCAP_LIBRARY}")
        include_directories(${PCAP_INCLUDE_DIR})
    else()
        message(FATAL_ERROR "Could not find the PCAP library")
    endif()
endif()

# Source files
set(SOURCE_FILES
    src/main.cpp
    src/packet_handler.cpp
    src/interface_selector.cpp
)

# Add the executable
add_executable(WifiPacketSniffer ${SOURCE_FILES})

# Link the PCAP library
if(PkgConfig_FOUND)
    target_link_libraries(WifiPacketSniffer ${PCAP_LIBRARIES})
else()
    target_link_libraries(WifiPacketSniffer ${PCAP_LIBRARY})
endif()

