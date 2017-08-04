#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "../lib_ops/rmRefh.h"
#include "JSONHandler.h"

class Reader {
public:
	Reader();
	void read( std::string message );
	rm::rmRef_h process_data( const char* data );
	virtual ~Reader();
};

#endif /* NETWORK_H_READER_H_ */