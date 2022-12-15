cmake_minimum_required(VERSION 3.22)
project(3D_Network_On_Chip)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/noc/topology)

add_executable(3D_Network_On_Chip
        src/noc/test/main.cpp
        src/noc/topology/TopologyConfig.cpp
        src/noc/topology/TopologyConfig.h
        src/noc/topology/Topology.cpp
        src/noc/topology/Topology.h)
