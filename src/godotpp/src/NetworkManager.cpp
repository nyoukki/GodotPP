//
// NetworkManager.cpp
//

#include "NetworkManager.h"

#include <vector>

#include "../../shared/messages/MessageFactory.h"
#include "../../shared/messages/RequestConnectionMessage.h"
#include "../../shared/messages/SpawnMessage.h"

using namespace godot;

void NetworkManager::ConnectToServer() {
    DataBuffer.resize(1024);

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

    ClassDB::bind_method(D_METHOD("get_type_map"), &NetworkManager::get_type_map);
    ClassDB::bind_method(D_METHOD("set_type_map"), &NetworkManager::set_type_map);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "server_ip"), "set_server_ip", "get_server_ip");
    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "type_map"), "set_type_map", "get_type_map");
}

NetworkManager::NetworkManager() {
    // Bind our socket to a random port
    Socket = net_socket_create("0.0.0.0:0");
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

void NetworkManager::set_type_map(Dictionary Dic) {
    TypeMap.clear();
    Array Keys = Dic.keys();

    for (int i = 0; i < Keys.size(); i++) {
        uint32_t id = (uint32_t)Keys[i];

        Ref<PackedScene> Scene = Dic[id];

        if (Scene.is_valid()) {
            TypeMap[id] = Scene;
        }
    }
}

Dictionary NetworkManager::get_type_map() {
    Dictionary dict;
    for (auto & It : TypeMap) {
        dict[It.key] = It.value;
    }
    return dict;
}


void NetworkManager::_process(double p_delta) {
    Node::_process(p_delta);

    int bytes = net_socket_poll(Socket, DataBuffer.data(), 1024, SenderBuffer, 64);

    if (bytes <= 0) return;

    std::unique_ptr<BaseMessage> Msg = MessageFactory::DeserializeMessage(DataBuffer);

    if (Msg->GetType() == MessageType::Spawn) {
        SpawnMessage* SpawnMsg = static_cast<SpawnMessage*>(Msg.get());

        Node* SceneRoot = get_tree()->get_current_scene();
        Context.CreateFromId(SpawnMsg->TypeId, SpawnMsg->TypeId, SceneRoot);
        godot::print_line("Spawn packet received");
    }
}

void NetworkManager::_ready() {
    Node::_ready();

    for (auto& It: TypeMap) {
        Context.RegisterType(It.key, It.value);
    }

    // Connect to the server
    ConnectToServer();
}
