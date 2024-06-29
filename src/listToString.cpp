#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

std::string serializeDataToJSON(const std::vector<std::unordered_map<std::string, std::string>>& data) {
    rapidjson::Document document;
    document.SetArray();

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    for (const auto& map : data) {
        rapidjson::Value obj(rapidjson::kObjectType);

        for (const auto& pair : map) {
            rapidjson::Value key(pair.first.c_str(), allocator);
            rapidjson::Value value(pair.second.c_str(), allocator);
            obj.AddMember(key, value, allocator);
        }

        document.PushBack(obj, allocator);
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();
}

int main() {
    std::vector<std::unordered_map<std::string, std::string>> data = {
            {{"key1", "value1"}, {"key2", "value2"}},
            {{"key3", "value3"}, {"key4", "value4"}}
    };

    std::string jsonStr = serializeDataToJSON(data);
    std::cout << jsonStr << std::endl;

    return 0;
}