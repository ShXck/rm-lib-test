#include "JSONHandler.h"

JSON_Handler::JSON_Handler() {
}

std::string JSON_Handler::build_new( const char* key, void* value, std::size_t size ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	std::string *casted_value = static_cast< std::string* >( value );

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	{
		rapidjson::Value value_str;
		value_str.SetString( casted_value->c_str(), _alloc );
		_doc.AddMember( "value", value_str, _alloc );
	}

	_doc.AddMember( "size", size, _alloc );
	_doc.AddMember( "instruction", 1, _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_get( const char* key ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	_doc.AddMember( "instruction", 2, _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_deleted( const char* key ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	_doc.AddMember( "instruction", 3, _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_set( Linked_List< std::string > list ) {

	std::cout << "List: " << std::endl;
	list.display();

	rapidjson::Document _doc;
	_doc.SetObject();
	rapidjson::Value array( rapidjson::kArrayType );
	Alloc _alloc = _doc.GetAllocator();

	for( int i = 0; i < list.size(); i++ ) {

		rapidjson::Value str_val;
		str_val.SetString( list.get( i ).c_str(), _alloc );

		array.PushBack( str_val, _alloc );
	}
	_doc.AddMember( "keys", array, _alloc );
	_doc.AddMember( "instruction", 4, _alloc );
	_doc.AddMember( "key", "empty", _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

rapidjson::Value& JSON_Handler::get_value( const char* json, const char* json_key ) {

	rapidjson::Document _doc;
	_doc.Parse( json );

	Alloc _alloc = _doc.GetAllocator();

	rapidjson::Value str_key;
	str_key.SetString( json_key, _alloc );

	rapidjson::Value& _val = _doc[ str_key ];

	return _val;
}

JSON_Handler::~JSON_Handler() {
	// TODO Auto-generated destructor stub
}

