#ifndef NETWORK_H_NETWORKHANDLER_H_
#define NETWORK_H_NETWORKHANDLER_H_
#define PORT_M 8000
#define PORT_HA 7500
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "../lib_ops/rmRefh.h"
#include "Reader.h"
#include "JSONHandler.h"
#include <thread>
#include <future>
#include "TempRefContainer.h"
#include "Encrypter.h"

class Network_Handler {
public:
	Network_Handler();
	void connect_to_main();
	void connect_to_ha();
	void wait_for_response();
	void wait_for_check_response();
	void send( std::string message );
	void check_server_status();
	rm::rmRef_h* get_resource();
	virtual ~Network_Handler();
private:
	sf::TcpSocket _socket;
	Reader _reader;
	Temp_Ref_Container ref_container;
	Encrypter _encrypter;
};

#endif /* NETWORK_H_NETWORKHANDLER_H_ */
