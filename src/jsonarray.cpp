#include <iostream>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

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

    return 0;
}