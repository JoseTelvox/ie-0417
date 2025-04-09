cmake_minimum_required(VERSION 3.10)
project(ComplexSoftwareProject)

set(CMAKE_CXX_STANDARD 17)

# ASIO can be header-only, but you can link boost if you need boost::asio
find_package(Threads REQUIRED)

# If using standalone ASIO
include_directories(/usr/include)

add_executable(ComplexSoftwareProject main.cpp)

target_link_libraries(ComplexSoftwareProject PRIVATE Threads::Threads)
