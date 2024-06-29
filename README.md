# testrapidjson

[rapidjson mainpage](https://rapidjson.org/)

[github mainpage](https://github.com/Tencent/rapidjson/)

[csdn reference](https://blog.csdn.net/stpeace/article/details/78149631)


`vcpkg install rapidjson`

{
	\"code\": 0,
	\"data\": [{
		\"id\": 1,
		\"path\": \"pa\"
	}, {
		\"id\": 2,
		\"path\": \"pa\"
	}]
}

```json

{"code": 0,"data": [{"id": 1,"path": "pa"}, {"id": 2,"path": "pa"}]}
```



## API

Document


```c++

Allocator& GetAllocator()

```


```c++

//! Type of JSON value

enum Type {
    kNullType = 0,      //!< null
    kFalseType = 1,     //!< false
    kTrueType = 2,      //!< true
    kObjectType = 3,    //!< object
    kArrayType = 4,     //!< array 
    kStringType = 5,    //!< string
    kNumberType = 6     //!< number
};

```



Value

```c++

GenericValue(Type type)

```

## map对象直接搞成json字符串，java可以

https://stackoverflow.com/questions/55587812/c-stdvector-to-json-array-with-rapidjson

泛型打印json、json array

在函数参数中，`std::string& code` 和 `std::string code` 有以下区别：

1. `std::string& code`：这是一个引用类型的参数，表示传递给函数的是原始 `std::string` 对象的引用。通过引用传递，函数可以直接修改原始对象的值。

   示例：
   ```cpp
   void modifyString(std::string& str) {
       str = "Modified";
   }
   
   int main() {
       std::string myString = "Original";
       modifyString(myString);
       std::cout << myString << std::endl;  // 输出 "Modified"
       return 0;
   }
   ```

2. `std::string code`：这是一个传值类型的参数，表示传递给函数的是原始 `std::string` 对象的副本。在函数内部对参数进行修改不会影响原始对象的值。

   示例：
   ```cpp
   void modifyString(std::string str) {
       str = "Modified";
   }
   
   int main() {
       std::string myString = "Original";
       modifyString(myString);
       std::cout << myString << std::endl;  // 输出 "Original"
       return 0;
   }
   ```

总结来说，使用 `std::string& code` 作为参数类型允许函数修改原始对象的值，而使用 `std::string code` 则在函数中操作参数时只会修改副本的值，不会影响原始对象。

选择使用哪种形式参数取决于你的需求。如果你想在函数内部修改原始对象的值，应该使用引用类型的参数；如果你只需要在函数中使用对象的值而不修改原始对象，传值类型的参数就足够了。
