#include "RMlib.h"

namespace rm {

RM_lib::RM_lib() : client_id( strdup(util::create_random_key( 5 ).c_str() ) ) {
	std::cout << "ID:" << client_id << std::endl;
}

void RM_lib::rm_init( int ip, int port, int ipHA, int portHA ) {
	_handler.make_connection();
}

void RM_lib::rm_new( const char* key, void* value, std::size_t size ) {
	std::string new_resource = JSON_Handler::build_new( key, value, client_id, size );
	_handler.send( new_resource );
	_handler.wait_for_response();
}


rmRef_h* RM_lib::rm_get( const char* key ) {
	std::string get_resource = JSON_Handler::build_get( key );
	_handler.send( get_resource );
	_handler.wait_for_response();
	return _handler.get_resource();
}

void RM_lib::rm_get_set( Linked_List< std::string > keys ) {
	std::string _set = JSON_Handler::build_set( keys );
	_handler.send( _set );
	_handler.wait_for_response();
}

void RM_lib::rm_delete( const char* key ) {
	std::string deleted_resource = JSON_Handler::build_deleted( key );
	_handler.send( deleted_resource );
	_handler.wait_for_response();
}

void RM_lib::rm_replace( const char* key, void* new_value ) {
	std::string replace_val = JSON_Handler::build_replace( key, new_value );
	_handler.send( replace_val );
	_handler.wait_for_response();
}

void RM_lib::rm_disconnect() {
	std::string dc_msg = JSON_Handler::build_dc_msg( client_id );
	_handler.send( dc_msg );
}


RM_lib::~RM_lib() {

}

} /* namespace rm */
