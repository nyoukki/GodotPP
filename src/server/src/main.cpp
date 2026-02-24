#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstring>
#include "snl.h"
#include "../include/Entities/EntityFactory.h"

#include "../../shared/messages/BaseMessage.h"
#include "../../shared/messages/MessageFactory.h"
#include "../include/LinkingContext.h"
#include "../include/NetworkManager.h"
#include "../../shared/messages/RequestConnectionMessage.h"

int main() {
    std::cout << "[C++] Starting UDP Socket..." << std::endl;

    GameSocket* sock = net_socket_create("127.0.0.1:62362");

    if (!sock) {
        std::cerr << "Failed to bind socket!" << std::endl;
        return -1;
    }

    std::cout << "[C++] Socket bound to 127.0.0.1:62362" << std::endl;

    // Create the LinkingContext
    LinkingContext Context;
    EntityFactory::RegisterAll(Context);

    // Create the Entity Registry
    entt::registry EntityRegistry;

    // Create the Network Manager
    NetworkManager NetManager(sock, EntityRegistry, Context);

    // The Game Loop
    char sender_buf[64];

    std::vector<uint8_t> data_buffer;
    data_buffer.resize(1024);

    while (true) {
        // Poll for data
        int bytes = net_socket_poll(sock, data_buffer.data(), 1024, sender_buf, 64);

        if (bytes > 0) {
            std::unique_ptr<BaseMessage> Msg = MessageFactory::DeserializeMessage(data_buffer);

            NetManager.HandleMessage(std::move(Msg), std::string(sender_buf));

        } else {
            std::cout << "." << std::flush;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Cleanup
    std::cout << "\n[C++] Destroying socket." << std::endl;
    net_socket_destroy(sock);

    return 0;
}
