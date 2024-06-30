cmake_minimum_required(VERSION 3.12)
project(testrapidjson)

set(CMAKE_CXX_STANDARD 11)
# 判断操作系统  
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")  
    # macOS 的情况  
    set(RAPIDJSON_INCLUDE_DIR "/usr/local/Cellar/rapidjson/1.1.0/include")  
    include_directories(${RAPIDJSON_INCLUDE_DIR})  
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")  
    # Windows 的情况（你可能需要设置不同的路径或使用其他方式找到头文件）  
    # set(RAPIDJSON_INCLUDE_DIR "C:/path/to/rapidjson/include") # 假设的路径  
    # include_directories(${RAPIDJSON_INCLUDE_DIR})  
else()  
    # Linux 或其他 Unix-like 系统的情况  
    # set(RAPIDJSON_INCLUDE_DIR "/usr/local/include/rapidjson") # 假设的路径  
    # include_directories(${RAPIDJSON_INCLUDE_DIR})  
endif()

add_executable(testrapidjson src/testrapidjson.cpp)
add_executable(jsonarray src/jsonarray.cpp)
add_executable(listToString src/listToString.cpp)
add_executable(listStrToJson src/listStrToJson.cpp)
add_executable(listStrToJson2 src/listStrToJson2.cpp)
