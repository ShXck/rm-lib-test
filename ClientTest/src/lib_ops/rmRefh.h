#ifndef LIB_OPS_RMREFH_H_
#define LIB_OPS_RMREFH_H_
#include <cstddef>

namespace rm {

class rmRef_h {
public:
	rmRef_h( const char* key, void* value, std::size_t size );
	void rm_init( int ip_m, int port_m, int ip_ha, int port_ha );
	bool operator == ( const rmRef_h& rm_h );
	bool operator != ( const rmRef_h& rm_h );
	std::size_t size();
	const char* key() const;
	void* value();
	virtual ~rmRef_h();
private:
	std::size_t _size;
	const char* _key;
	void* _value;
};

} /* namespace rm */

#endif /* LIB_OPS_RMREFH_H_ */