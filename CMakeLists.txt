cmake_minimum_required(VERSION 3.12)
project(testrapidjson)

set(CMAKE_CXX_STANDARD 11)

add_executable(testrapidjson testrapidjson.cpp)

find_package(RapidJSON CONFIG REQUIRED)
target_include_directories(testrapidjson PRIVATE ${RAPIDJSON_INCLUDE_DIRS})