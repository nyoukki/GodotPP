//
// NetworkManager.h
//

#ifndef GODOTPP_NETWORKMANAGER_H
#define GODOTPP_NETWORKMANAGER_H
#include <string>
#include <vector>

#include "LinkingContext.h"
#include "snl.h"
#include "../../shared/messages/BaseMessage.h"


class NetworkManager {

private:
    // We should use UUIDs later to identify connexions, since client IPs can change
    std::vector<std::string> ClientConnections;

    LinkingContext& Context;
    entt::registry& Registry;
    GameSocket* Socket;

    void HandleNewConnection(const std::string &IP);

public:
    NetworkManager(GameSocket* Socket, entt::registry& Registry, LinkingContext& Context);

    void SendMessage(BaseMessage& Message, const std::string &IP) const;
    void BroadcastMessage(BaseMessage& Message) const;

    void HandleMessage(std::unique_ptr<BaseMessage> Message, const std::string &IP);
    bool IsClientConnected(const std::string &IP);
};


#endif //GODOTPP_NETWORKMANAGER_H