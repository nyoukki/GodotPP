//
// NetworkManager.cpp
//

#include "../include/NetworkManager.h"

#include <algorithm>
#include <iostream>

#include "../include/LinkingContext.h"
#include "../../shared/messages/MessageFactory.h"
#include "../../shared/messages/SpawnMessage.h"

void NetworkManager::HandleNewConnection(const std::string &IP) {
    if (!IsClientConnected(IP)) {
        // Handle connection
        ClientConnections.emplace_back(IP);

        // Create entity
        LinkingContext::ObjectContext NewEntity = Context.CreateFromTypeId(EntityType::Player, Registry);

        // Send Spawn packet
        SpawnMessage Msg;
        Msg.NetworkId = NewEntity.NetworkId;
        Msg.TypeId = static_cast<uint32_t>(EntityType::Player);

        BroadcastMessage(Msg);

        std::cout << "Client " << IP << " connected. Spawning entity ID " << NewEntity.NetworkId << std::endl;
    }
}

NetworkManager::NetworkManager(GameSocket *Socket, entt::registry &Registry, LinkingContext &Context):
    Context(Context), Registry(Registry), Socket(Socket) {}

void NetworkManager::SendMessage(BaseMessage &Message, const std::string &IP) const {
    std::vector<uint8_t> send_buffer;
    const uintptr_t len = MessageFactory::SerializeMessage(Message, send_buffer);
    net_socket_send(Socket, IP.data(), send_buffer.data(), len);
}

void NetworkManager::BroadcastMessage(BaseMessage &Message) const {
    std::vector<uint8_t> send_buffer;
    const uintptr_t len = MessageFactory::SerializeMessage(Message, send_buffer);
    for (std::string IP: ClientConnections) {
        net_socket_send(Socket, IP.data(), send_buffer.data(), len);
    }
}

void NetworkManager::HandleMessage(std::unique_ptr<BaseMessage> Message, const std::string &IP) {
    if (Message->GetType() == MessageType::RequestConnection) {
        HandleNewConnection(IP);
    }
    else if (Message->GetType() == MessageType::Spawn) {
        SpawnMessage* SpawnMsg = static_cast<SpawnMessage*>(Message.get());
        std::cout << "[Server] Received my own Spawn message with entity ID " << SpawnMsg->NetworkId << std::endl;
    }
}

bool NetworkManager::IsClientConnected(const std::string &IP) {
    return std::find(ClientConnections.begin(), ClientConnections.end(), IP) != ClientConnections.end();
}
