#include "RMlib.h"

namespace rm {

RM_lib::RM_lib() {
	// TODO Auto-generated constructor stub

}

void RM_lib::rm_init( int ip, int port, int ipHA, int portHA ) {
	_handler.make_connection();
}

void RM_lib::rm_new( const char* key, void* value, std::size_t size ) {
	std::string new_resource = JSON_Handler::build_new( key, value, size );
	_handler.send( new_resource );
	_handler.wait_for_response();
}


rmRef_h* RM_lib::rm_get( const char* key ) {
	std::string get_resource = JSON_Handler::build_get( key );
	_handler.send( get_resource );
	_handler.wait_for_response();
	return _handler.get_resource();
}

void RM_lib::rm_delete( rmRef_h* handler ) {
	std::string deleted_resource = JSON_Handler::build_deleted( handler->_key );
	_handler.send( deleted_resource );
	_handler.wait_for_response();
}

void RM_lib::rm_replace( const char* key, void* new_value ) {

}

rmRef_h& RM_lib::find_rm_ref( std::string tmp_key ) {
	rmRef_h tmp_ref( nullptr, 0, tmp_key.c_str() );
	return rm_refs.get( tmp_ref );
}

RM_lib::~RM_lib() {

}

} /* namespace rm */
