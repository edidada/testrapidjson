#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

template<typename T>
std::string serializeDataToJSON(const T& data, const std::string& code, const std::string& message) {
    rapidjson::Document document;
    document.SetObject();
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    // Add data objects to "list" array
    rapidjson::Value list(rapidjson::kArrayType);
    for (const auto& item : data) {
        rapidjson::Value obj(rapidjson::kObjectType);
        for (const auto& pair : item) {
            rapidjson::Value key(pair.first.c_str(), allocator);
            rapidjson::Value value(pair.second.c_str(), allocator);
            obj.AddMember(key, value, allocator);
        }
        list.PushBack(obj, allocator);
    }
    document.AddMember("list", list, allocator);

    // Add code and message
    rapidjson::Value jsonCode(code.c_str(), allocator);
    rapidjson::Value jsonMessage(message.c_str(), allocator);
    document.AddMember("code", jsonCode, allocator);
    document.AddMember("message", jsonMessage, allocator);

    // Convert to JSON string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();
}

int main() {
    std::vector<std::unordered_map<std::string, std::string>> data = {
            {{"attendResultId", "0aa620e7aee74ba79ee6558950a1ed45"}, {"date", "2024-06-28"}, {"firstShouldInTime", "2024-06-28T20:27:13.000+08:00"}, {"firstShouldOutTime", "2024-06-29T08:32:37.000+08:00"}, {"personId", "YS0275"}},
            {{"attendResultId", "5082233b7c654227a848ca1e80c1fdf4"}, {"date", "2024-06-28"}, {"firstShouldInTime", "2024-06-28T20:20:34.000+08:00"}, {"firstShouldOutTime", "2024-06-29T07:51:48.000+08:00"}, {"personId", "YS0371"}}
    };

    std::string code = "200";
    std::string message = "success";

    std::string jsonStr = serializeDataToJSON(data, code, message);
    std::cout << jsonStr << std::endl;

    return 0;
}