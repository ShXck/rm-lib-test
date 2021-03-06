#include "JSONHandler.h"

JSON_Handler::JSON_Handler() {
}

std::string JSON_Handler::build_new( const char* key, void* value, char* id, std::size_t size ) {

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
		rapidjson::Value str_id;
		str_id.SetString( id, _alloc );
		_doc.AddMember( "id", str_id, _alloc );
	}

	{
		rapidjson::Value value_str;
		value_str.SetString( casted_value->c_str(), _alloc );
		_doc.AddMember( "value", value_str, _alloc );
	}

	_doc.AddMember( "size", size, _alloc );
	_doc.AddMember( "instruction", NEW, _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_new( const char* key, std::string value, char* id, std::size_t size ) {

	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	{
		rapidjson::Value str_id;
		str_id.SetString( id, _alloc );
		_doc.AddMember( "id", str_id, _alloc );
	}

	{
		rapidjson::Value value_str;
		value_str.SetString( value.c_str(), _alloc );
		_doc.AddMember( "value", value_str, _alloc );
	}

	_doc.AddMember( "size", size, _alloc );
	_doc.AddMember( "instruction", NEW, _alloc );

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

	_doc.AddMember( "instruction", GET, _alloc );

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

	_doc.AddMember( "instruction", DELETE, _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_set( Linked_List< std::string > list ) {

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
	_doc.AddMember( "instruction", VAL_SET, _alloc );
	_doc.AddMember( "key", "empty", _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_replace( const char* key, void* new_val ) {
	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	std::string *casted_value = static_cast< std::string* >( new_val );

	{
		rapidjson::Value str_key;
		str_key.SetString( key, _alloc );
		_doc.AddMember( "key", str_key, _alloc );
	}

	{
		rapidjson::Value str_val;
		str_val.SetString( casted_value->c_str(), _alloc );
		_doc.AddMember( "new_value", str_val, _alloc );
	}

	_doc.AddMember( "instruction", REPLACE, _alloc );

	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_dc_msg( char* key ) {
	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	{
		rapidjson::Value str_id;
		str_id.SetString( key, _alloc );
		_doc.AddMember( "key", str_id, _alloc );
	}

	_doc.AddMember( "instruction", DISCONNECT, _alloc );
	rapidjson::StringBuffer str_buffer;
	Writer _writer( str_buffer );
	_doc.Accept( _writer );

	return str_buffer.GetString();
}

std::string JSON_Handler::build_check_msg() {
	rapidjson::Document _doc;
	_doc.SetObject();
	Alloc _alloc = _doc.GetAllocator();

	_doc.AddMember( "instruction", 8, _alloc );
	_doc.AddMember( "key", "NONE", _alloc );

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

JSON_Handler::~JSON_Handler() { }

