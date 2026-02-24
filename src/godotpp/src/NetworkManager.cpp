//
// NetworkManager.cpp
//

#include "NetworkManager.h"

#include <vector>

#include "../../shared/messages/MessageFactory.h"
#include "../../shared/messages/RequestConnectionMessage.h"

using namespace godot;

void NetworkManager::ConnectToServer() {
    // This way of connecting is temporary, replace with a more robust protocol later
    RequestConnectionMessage Message;
    std::vector<uint8_t> send_buffer;
    send_buffer.resize(64);
    MessageFactory::SerializeMessage(Message, send_buffer);

    net_socket_send(Socket, ServerIP.data(), send_buffer.data(), send_buffer.size());
}

void NetworkManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_server_ip"), &NetworkManager::get_server_ip);
    ClassDB::bind_method(D_METHOD("set_server_ip"), &NetworkManager::set_server_ip);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "server_ip"), "set_server_ip", "get_server_ip");
}

NetworkManager::NetworkManager() {
    // Bind our socket to a random port
    Socket = net_socket_create("0.0.0.0:0");

    // Connect to the server
    ConnectToServer();
}

NetworkManager::~NetworkManager() {
    net_socket_destroy(Socket);
}

void NetworkManager::set_server_ip(const String &ip) {
    ServerIP = ip.utf8().get_data();
}

String NetworkManager::get_server_ip() const {
    String s;
    s.utf8() = ServerIP.data();
    return s;
}

void NetworkManager::_process(double p_delta) {
    Node::_process(p_delta);
}
