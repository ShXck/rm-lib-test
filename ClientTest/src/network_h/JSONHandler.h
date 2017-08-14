#ifndef NETWORK_H_JSONHANDLER_H_
#define NETWORK_H_JSONHANDLER_H_
#include <cstddef>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "../data_structs/LinkedList.h"


class JSON_Handler {
	typedef rapidjson::Document::AllocatorType& Alloc;
	typedef rapidjson::Writer< rapidjson::StringBuffer > Writer;
public:
	JSON_Handler();
	static std::string build_new( const char* key, void* value, std::size_t size );
	static std::string build_get( const char* key );
	static std::string build_deleted( const char* key );
	static std::string build_set( Linked_List < std::string > list );
	static rapidjson::Value& get_value ( const char* json, const char* json_key );
	virtual ~JSON_Handler();
};

#endif /* NETWORK_H_JSONHANDLER_H_ */
