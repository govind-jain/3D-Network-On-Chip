cmake_minimum_required(VERSION 3.22)
project(3D_Network_On_Chip)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/noc/topology)

add_executable(3D_Network_On_Chip
        src/noc/test/main.cpp
        src/noc/test/Start.hpp
        src/noc/test/Start.cpp
        src/noc/packet/Packet.cpp
        src/noc/packet/Packet.hpp
        src/noc/controller/NetworkController.cpp
        src/noc/controller/NetworkController.hpp
        src/noc/topology/TopologyConfig.cpp
        src/noc/topology/TopologyConfig.hpp
        src/noc/topology/Topology.cpp
        src/noc/topology/Topology.hpp
        src/noc/node/node.cpp
        src/noc/node/node.hpp
        src/noc/Routing/Routing.cpp
        src/noc/Routing/ShortestPathRouting.cpp
        src/noc/Routing/Routing.hpp
        src/noc/Routing/ShortestPathRouting.hpp
        )

