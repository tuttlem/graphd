cmake_minimum_required(VERSION 3.15)
project(graphd)

set(CMAKE_CXX_STANDARD 17)

set(Boost_NO_BOOST_CMAKE TRUE)
set(BOOST_ROOT /home/michael/Source/lib/boost_1_77_0)
set(Boost_INCLUDE_DIR /home/michael/Source/lib/boost_1_77_0/include)
set(Boost_LIBRARY_DIR /home/michael/Source/lib/boost_1_77_0/lib)

# unset(Boost_LIBRARIES)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

# boost components
find_package(Boost 1.77.0 REQUIRED COMPONENTS log log_setup system filesystem date_time thread chrono)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/conf/graphd.conf ${CMAKE_CURRENT_BINARY_DIR}/graphd.conf COPYONLY)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(graphd src/main.cpp src/core/server.cpp src/core/server.hpp src/types/errors.hpp src/common.hpp src/core/telemetry.cpp src/core/telemetry.hpp src/types/interfaces.hpp src/db/types/id.cpp src/db/types/id.hpp src/core/log.hpp src/core/log.cpp src/core/config.cpp src/core/config.hpp src/db/database.cpp src/db/database.hpp src/db/types/interfaces.hpp src/db/graph.cpp src/db/graph.hpp src/db/vertex.cpp src/db/vertex.hpp src/db/edge.cpp src/db/edge.hpp src/db/io/serialization.hpp)
target_link_libraries(graphd ${Boost_LIBRARIES})

