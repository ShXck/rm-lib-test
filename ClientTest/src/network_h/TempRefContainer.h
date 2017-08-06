#ifndef NETWORK_H_TEMPREFCONTAINER_H_
#define NETWORK_H_TEMPREFCONTAINER_H_
#include "../lib_ops/rmRefh.h"


class Temp_Ref_Container {
public:
	Temp_Ref_Container();
	bool is_null();
	void set_ref( rm::rmRef_h* ref );
	rm::rmRef_h* ref();
	virtual ~Temp_Ref_Container();
private:
	rm::rmRef_h* tmp_ref;
};

#endif /* NETWORK_H_TEMPREFCONTAINER_H_ */