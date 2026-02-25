//
// NetworkManager.h
//

#ifndef GODOTPP_NETWORKMANAGER_H
#define GODOTPP_NETWORKMANAGER_H
#include <string>
#include <vector>
#include <godot_cpp/classes/node.hpp>

#include "snl.h"

namespace godot {
    class NetworkManager: public Node {
        GDCLASS(NetworkManager, Node);

    private:
        GameSocket* Socket;
        std::string ServerIP = "127.0.0.1:62362";

        std::vector<uint8_t> DataBuffer;
        char SenderBuffer[64];

        void ConnectToServer();

    protected:
        static void _bind_methods();

    public:
        NetworkManager();
        ~NetworkManager();

        void set_server_ip(const String &ip);
        String get_server_ip() const;

        void _process(double p_delta) override;
    };
}


#endif //GODOTPP_NETWORKMANAGER_H