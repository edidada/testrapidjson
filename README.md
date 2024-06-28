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
