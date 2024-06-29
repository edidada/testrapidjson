cmake_minimum_required(VERSION 3.12)
project(testrapidjson)

set(CMAKE_CXX_STANDARD 11)

add_executable(testrapidjson src/testrapidjson.cpp)
add_executable(jsonarray src/jsonarray.cpp)
add_executable(listToString src/listToString.cpp)
add_executable(listStrToJson src/listStrToJson.cpp)
add_executable(listStrToJson2 src/listStrToJson2.cpp)
