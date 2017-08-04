#ifndef LIB_OPS_RMLIB_H_
#define LIB_OPS_RMLIB_H_
#define PORT_M 8000
#define PORT_HA 7500
#include <cstddef>
#include <string>
#include "rmRefh.h"
#include "../network_h/NetworkHandler.h"
#include "../network_h/JSONHandler.h"
#include "../data_structs/LinkedList.h"

namespace rm {

class RM_lib {
public:
	RM_lib();
	void rm_init( int ip_m, int port_m, int ip_HA, int port_HA );
	void rm_new( const char* key, void* value, std::size_t size );
	rmRef_h rm_get( const char* key );
	void rm_delete( rmRef_h* handler );
	virtual ~RM_lib();
private:
	void rm_send( std::string message );
private:
	Network_Handler _handler;
	Linked_List<rmRef_h> rm_refs;

};

} /* namespace rm */

#endif /* LIB_OPS_RMLIB_H_ */