#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstring>
#include "snl.h"

#include "../include/messages/BaseMessage.h"
#include "../include/messages/SpawnMessage.h"
#include "../include/messages/MessageFactory.h"

int main() {
    std::cout << "[C++] Starting UDP Socket..." << std::endl;

    GameSocket* sock = net_socket_create("127.0.0.1:62362");

    if (!sock) {
        std::cerr << "Failed to bind socket!" << std::endl;
        return -1;
    }

    std::cout << "[C++] Socket bound to 127.0.0.1:62362" << std::endl;

    SpawnMessage TestMsg;
    TestMsg.NetworkId = 123;
    std::vector<uint8_t> send_buffer;
    send_buffer.resize(64);
    MessageFactory::SerializeMessage(TestMsg, send_buffer);

    // Sending a test message to ourselves
    const char* target = "127.0.0.1:62362";
    net_socket_send(sock, target, send_buffer.data(), send_buffer.size());

    // The Game Loop
    char sender_buf[64];

    std::vector<uint8_t> data_buffer;
    data_buffer.resize(1024);

    while (true) {
        // Poll for data
        int bytes = net_socket_poll(sock, data_buffer.data(), 1024, sender_buf, 64);

        if (bytes > 0) {
            std::unique_ptr<BaseMessage> Msg = MessageFactory::DeserializeMessage(data_buffer);
            if (Msg->GetType() == MessageType::Spawn) {
                auto SpawnMsg = static_cast<SpawnMessage*>(Msg.get());
                std::cout << "Spawned entity with id " << SpawnMsg->NetworkId << std::flush;
            }
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