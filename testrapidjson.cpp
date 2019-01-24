#include <iostream>
#include <map>

#include "rapidjson/prettywriter.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "rapidjson/memorystream.h"
#include <sys/types.h>
#include <vector>

using namespace std;
using rapidjson::Document;
using rapidjson::StringBuffer;
using rapidjson::Writer;
using namespace rapidjson;


// 注意int和uint64_t
map<string, uint64_t> g_mChildInt;
map<string, string> g_mChildString;

string formJson(const map<string,int> &mInt,
        const map<string, string> &mString,
		const string &strChild="",
		const map<string, uint64_t> &mChildInt=g_mChildInt,
		const map<string, string> &mChildString=g_mChildString,
		const string &strChild2="",
		const map<string, uint64_t> &mChildInt2=g_mChildInt,
		const map<string, string> &mChildString2=g_mChildString

{
	Document document;

    Document::AllocatorType& allocator = document.GetAllocator();
    Value root(kObjectType);

    Value key(kStringType);
    Value value(kStringType);

	// 当前级别
	for(map<string, int>::const_iterator it = mInt.begin(); it != mInt.end(); ++it)
	{
		key.SetString(it->first.c_str(), allocator);
    	root.AddMember(key, it->second, allocator);
	}

	for(map<string, string>::const_iterator it = mString.begin(); it != mString.end(); ++it)
	{
		key.SetString(it->first.c_str(), allocator);
   		value.SetString(it->second.c_str(), allocator);
    	root.AddMember(key, value, allocator);
	}

	// 孩子级别
	if(!strChild.empty())
	{
		Value child(kObjectType);
		for(map<string, uint64_t>::const_iterator it = mChildInt.begin(); it != mChildInt.end(); ++it)
		{
			key.SetString(it->first.c_str(), allocator);
	    	child.AddMember(key, it->second, allocator);
		}

		for(map<string, string>::const_iterator it = mChildString.begin(); it != mChildString.end(); ++it)
		{
			key.SetString(it->first.c_str(), allocator);
	   		value.SetString(it->second.c_str(), allocator);
	    	child.AddMember(key, value, allocator);
		}

		key.SetString(strChild.c_str(), allocator);
		root.AddMember(key, child, allocator);
	}

	// 孩子级别
	if(!strChild2.empty())
	{
		Value child(kObjectType);
		for(map<string, uint64_t>::const_iterator it = mChildInt2.begin(); it != mChildInt2.end(); ++it)
		{
			key.SetString(it->first.c_str(), allocator);
	    	child.AddMember(key, it->second, allocator);
		}

		for(map<string, string>::const_iterator it = mChildString2.begin(); it != mChildString2.end(); ++it)
		{
			key.SetString(it->first.c_str(), allocator);
	   		value.SetString(it->second.c_str(), allocator);
	    	child.AddMember(key, value, allocator);
		}

		key.SetString(strChild2.c_str(), allocator);
		root.AddMember(key, child, allocator);
	}

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    root.Accept(writer);
    return buffer.GetString();

}


string formJsonWithArray(const map<string, int> &mInt, const map<string, string> &mString,
				const string &strChild1, const map<string, uint64_t> &mChildInt, const map<string, string> &mChildString,
		        string &strChild2, vector<map<string, uint64_t> >&mVecChildInt, vector<map<string, string> >&mVecChildString){
	Document document;

    Document::AllocatorType& allocator = document.GetAllocator();
    Value root(kObjectType);

    Value key(kStringType);
    Value value(kStringType);

	// 当前级别
	for(map<string, int>::const_iterator it = mInt.begin(); it != mInt.end(); ++it)
	{
		key.SetString(it->first.c_str(), allocator);
    	root.AddMember(key, it->second, allocator);
	}

	for(map<string, string>::const_iterator it = mString.begin(); it != mString.end(); ++it)
	{
		key.SetString(it->first.c_str(), allocator);
   		value.SetString(it->second.c_str(), allocator);
    	root.AddMember(key, value, allocator);
	}

	// 孩子级别
	if(!strChild1.empty())
	{
		Value child(kObjectType);
		for(map<string, uint64_t>::const_iterator it = mChildInt.begin(); it != mChildInt.end(); ++it)
		{
			key.SetString(it->first.c_str(), allocator);
	    	child.AddMember(key, it->second, allocator);
		}

		for(map<string, string>::const_iterator it = mChildString.begin(); it != mChildString.end(); ++it)
		{
			key.SetString(it->first.c_str(), allocator);
	   		value.SetString(it->second.c_str(), allocator);
	    	child.AddMember(key, value, allocator);
		}

		key.SetString(strChild1.c_str(), allocator);
		root.AddMember(key, child, allocator);
	}

	// 孩子级别
	unsigned int uiSize1 = mVecChildInt.size();
	unsigned int uiSize2 = mVecChildString.size();
	if(!strChild2.empty() && uiSize1 == uiSize2)
	{
		Value array(rapidjson::kArrayType);
		for(unsigned int i = 0; i < uiSize1; ++i)
		{
			Value child(kObjectType);
			for(map<string, uint64_t>::iterator it = mVecChildInt[i].begin(); it != mVecChildInt[i].end(); ++it)
			{
				key.SetString(it->first.c_str(), allocator);
		    	child.AddMember(key, it->second, allocator);

			}

			for(map<string, string>::iterator it = mVecChildString[i].begin(); it != mVecChildString[i].end(); ++it)
			{
				key.SetString(it->first.c_str(), allocator);
		   		value.SetString(it->second.c_str(), allocator);
		    	child.AddMember(key, value, allocator);
			}

			array.PushBack(child, allocator);

		}

		key.SetString(strChild2.c_str(), allocator);
		root.AddMember(key, array, allocator);

	}

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    root.Accept(writer);
    return buffer.GetString();
}

class NameBean{

public:
    string name;
    int id;
    string toString(){
        return "name:"+name+" id:"+to_string(id);
    }
};

void makejson()
{
	map<string, int> mInt;
	map<string, string> mString;
	mInt["code"] = 0;
	mString["msg"] = "ok";

	string strChild1 = "xxx";
	map<string, uint64_t> mChildInt1;
	map<string, string> mChildString1;
	mChildInt1["key"] = 729;
	mChildString1["kk"] = "vv";

	string strChild2 = "yyy";
	map<string, uint64_t> mChildInt2;
	map<string, string> mChildString2;
	mChildInt2["key"] = 730;
	mChildString2["kkk"] = "vvv";

	string s = formJson(mInt, mString, strChild1, mChildInt1, mChildString1,strChild2, mChildInt2, mChildString2);
	cout << s << endl;
}

void makejsons()
{
    map<string, int> mInt;
    map<string, string> mString;
    mInt["code"] = 0;
    mString["msg"] = "ok";

    string strChild1 = "account";
    map<string, uint64_t> mChildInt1;
    map<string, string> mChildString1;
    mChildInt1["id"] = 1;
    mChildString1["username"] = "edidada";

    string strChild2 = "loginresult";
    map<string, uint64_t> mChildInt2;
    map<string, string> mChildString2;
    mChildInt2["code"] = 730;
    mChildString2["msg"] = "loginsuccess";

    string s = formJson(mInt, mString, strChild1, mChildInt1, mChildString1,strChild2, mChildInt2, mChildString2);
    cout << s << endl;
}


void makeJsonArray()
{
	map<string, int> mInt;
	map<string, string> mString;
	mInt["code"] = 0;
	mString["msg"] = "ok";

	string strChild1 = "xxx";
	map<string, uint64_t> mChildInt;
	map<string, string> mChildString;
	mChildString["kk"] = "vv";
	mChildInt["key"] = 729;


	string strChild2 = "data";
	vector<map<string, uint64_t> >mVecChildInt;
	vector<map<string, string> >mVecChildString;

	{

		map<string, uint64_t> mChildInt;
		map<string, string> mChildString;

		mChildInt["id"] = 1;
		mChildString["path"] = "pa";
		mChildString["sha"] = "sh";

		mVecChildInt.push_back(mChildInt);
		mVecChildString.push_back(mChildString);
	}

	{

		map<string, uint64_t> mChildInt;
		map<string, string> mChildString;

		mChildInt["id"] = 2;
		mChildString["path"] = "pa";
		mChildString["sha"] = "sh";

		mVecChildInt.push_back(mChildInt);
		mVecChildString.push_back(mChildString);
	}

	string s = formJsonWithArray(mInt, mString, strChild1, mChildInt, mChildString, strChild2, mVecChildInt, mVecChildString);
	cout << s << endl;
}



void parseJson(){
    // 1. 把 JSON 解析至 DOM。
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. 利用 DOM 作出修改。
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // Output stars :11
    std::cout <<"stars :"<<s.GetInt() << std::endl;
    s = d["project"];

    // Output project :rapidjson
    std::cout <<"project :"<<s.GetString() << std::endl;

    // 3. 把 DOM 转换（stringify）成 JSON。
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
}

void parseJsonList(){
    const char * str="{\"code\": 0,\"data\": [{\"id\": 1,\"path\": \"pa\"}, {\"id\": 2,\"path\": \"pa\"}]}";
    Document d;
    d.Parse(str);
    //data
    // 2. 利用 DOM 作出修改。
    Value& ques = d["data"];
    if (ques.IsArray()){
        vector<NameBean> nameBeanVector;
        for(size_t i = 0; i < ques.Size(); ++i){
            Value & v = ques[i];
            NameBean nameBean;
            if(v.HasMember("path") && v["path"].IsString()){
                nameBean.name=v["path"].GetString();
            }
            if(v.HasMember("id") && v["id"].IsInt()){
                nameBean.id=v["id"].GetInt();
            }
            nameBeanVector.push_back(nameBean);
        }
        for (int i = 0; i<nameBeanVector.size(); i++)
        {
            cout<<nameBeanVector[i].toString()<< " ";
        }
        cout<<endl;
    }
}


int main(int argc, char *argv[])
{
    makejson();
    makejsons();
    makeJsonArray();

    parseJson();
    parseJsonList();
    return 0;
}
