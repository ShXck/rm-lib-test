#ifndef LIB_OPS_RMLIB_H_
#define LIB_OPS_RMLIB_H_

#define PORT_M 8000
#define PORT_HA 7500

#include <cstddef>
#include <string>
#include <iostream>
#include "rmRefh.h"
#include "../network_h/NetworkHandler.h"
#include "../network_h/JSONHandler.h"
#include "../data_structs/LinkedList.h"
#include "../util.hpp"

namespace rm {


class RM_lib {
public:
	RM_lib();
	void rm_init( int ip_m, int port_m, int ip_HA, int port_HA );
	void rm_new( const char* key, void* value, std::size_t size );
	rmRef_h* rm_get( const char* key );
	void rm_get_set( Linked_List< std::string > keys );
	void rm_delete( const char* key );
	void rm_replace( const char* key, void* new_value );
	void rm_disconnect();
	virtual ~RM_lib();
private:
	Network_Handler _handler;
	char* client_id;
};

} /* namespace rm */

#endif /* LIB_OPS_RMLIB_H_ */
