#include <iostream>
#include <unordered_map>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
void makeMapJson(){
        rapidjson::Document document;
    document.SetArray();

    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"key1", "value1"}, {"key2", "value2"}},
        {{"key3", "value3"}, {"key4", "value4"}}
    };

    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

    for (const auto& map : data) {
        rapidjson::Value mapValue(rapidjson::kObjectType);
        for (const auto& pair : map) {
            rapidjson::Value key, value;
            key.SetString(pair.first.c_str(), pair.first.length(), allocator);
            value.SetString(pair.second.c_str(), pair.second.length(), allocator);
            mapValue.AddMember(key, value, allocator);
        }
        document.PushBack(mapValue, allocator);
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    std::cout << buffer.GetString() << std::endl;

}

int main() {
    rapidjson::Document document;
    document.SetArray();

    std::vector<std::string> files = {"abc", "def"};
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    for (const auto file : files) {
        rapidjson::Value value;
        value.SetString(file.c_str(), file.length(), allocator);
        document.PushBack(value, allocator);
        // Or as one liner:
        // document.PushBack(rapidjson::Value().SetString(file.c_str(), file.length(), allocator), allocator);
    }

    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    document.Accept(writer);

    std::cout << strbuf.GetString();

makeMapJson();
    return 0;
}