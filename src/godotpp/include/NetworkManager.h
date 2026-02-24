//
// NetworkManager.h
//

#ifndef GODOTPP_NETWORKMANAGER_H
#define GODOTPP_NETWORKMANAGER_H
#include <string>
#include <godot_cpp/classes/node.hpp>

#include "snl.h"

namespace godot {
    class NetworkManager: public Node {
        GDCLASS(NetworkManager, Node);

    private:
        GameSocket* Socket;
        std::string ServerIP = "127.0.0.1:62362";

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