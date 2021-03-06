cmake_minimum_required(VERSION 3.6)
project(Part_2)
if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(BOOST_ROOT CACHE PATH "/usr/local/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
include_directories(/usr/local/include)
set(SOURCE_FILES World/Point.cpp World/Point.h World/Grid.cpp World/Grid.h World/Map.h World/Bfs.cpp World/Bfs.h World/GridPoint.h World/GridPoint.cpp TaxiStation/Vehicles/Cab.h TaxiStation/Trip.cpp TaxiStation/Trip.h TaxiStation/Passenger.cpp TaxiStation/Passenger.h TaxiStation/TaxiCenter.cpp TaxiStation/TaxiCenter.h TaxiStation/Driver.cpp TaxiStation/Driver.h TaxiStation/Vehicles/StandardCab.cpp TaxiStation/Vehicles/StandardCab.h TaxiStation/Vehicles/LuxuryCab.cpp TaxiStation/Vehicles/LuxuryCab.h Socketing/Socket.cpp Socketing/Socket.h Socketing/Udp.cpp Socketing/Udp.h World/Clock.cpp World/Clock.h MainFlow/Server.cpp MainFlow/Server.h MainFlow/Job.cpp MainFlow/Job.h MainFlow/ThreadPool.cpp MainFlow/ThreadPool.h MainFlow/TaxiWorld.cpp MainFlow/TaxiWorld.h)
#set(SOURCE_FILES TaxiStation/Point.cpp TaxiStation/Point.h TaxiStation/Grid.cpp TaxiStation/Grid.h TaxiStation/Map.h TaxiStation/Bfs.cpp TaxiStation/Bfs.h TaxiStation/GridPoint.h TaxiStation/GridPoint.cpp TaxiStation/Cab.h TaxiStation/Trip.cpp TaxiStation/Trip.h TaxiStation/Passenger.cpp TaxiStation/Passenger.h TaxiStation/TaxiCenter.cpp TaxiStation/TaxiCenter.h TaxiStation/Driver.cpp TaxiStation/Driver.h TaxiStation/Listener.h TaxiStation/StandardCab.cpp TaxiStation/StandardCab.h TaxiStation/LuxuryCab.cpp TaxiStation/LuxuryCab.h TaxiStation/ServerMain.cpp tests/Bfs_test.cpp tests/CabTest.cpp tests/DriverTest.cpp tests/GridPointTest.cpp tests/GridTest.cpp tests/PassengerTest.cpp tests/PointTest.cpp tests/TaxiStationTest.cpp tests/TripTest.cpp TaxiStation/ClientMain.cpp Socketing/Socket.cpp Socketing/Socket.h Socketing/Udp.cpp Socketing/Udp.h)
add_executable(Client ${SOURCE_FILES} MainFlow/ClientMain.cpp Socketing/Tcp.cpp Socketing/Tcp.h MainFlow/Client.cpp MainFlow/Client.h)
add_executable(Server ${SOURCE_FILES} MainFlow/ServerMain.cpp)
target_link_libraries(Server ${Boost_LIBRARIES})
target_link_libraries(Client ${Boost_LIBRARIES})
#target_link_libraries(Main gtest gtest_main)