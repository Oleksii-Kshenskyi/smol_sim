# Add vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "C:/Users/oleks/gitproj/smol_sim/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.26)
project(smol_sim)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SRC_DIR})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find and link fmt
find_package(EnTT CONFIG REQUIRED)
find_package(Box2D CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cxx)
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT box2d::box2d sfml-system sfml-graphics sfml-window)