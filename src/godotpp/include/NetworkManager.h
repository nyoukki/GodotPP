//
// NetworkManager.h
//

#ifndef GODOTPP_NETWORKMANAGER_H
#define GODOTPP_NETWORKMANAGER_H
#include <string>
#include <vector>
#include <godot_cpp/classes/node.hpp>

#include "snl.h"
#include "godot_cpp/classes/packed_scene.hpp"
#include "../include/LinkingContext.h"

namespace godot {
    class NetworkManager: public Node {
        GDCLASS(NetworkManager, Node);

    private:
        GameSocket* Socket;
        std::string ServerIP = "127.0.0.1:62362";

        HashMap<uint32_t, Ref<PackedScene>> TypeMap;

        std::vector<uint8_t> DataBuffer;
        char SenderBuffer[64];

        LinkingContext Context;

        void ConnectToServer();

    protected:
        static void _bind_methods();

    public:
        NetworkManager();
        ~NetworkManager();

        void set_server_ip(const String &ip);
        String get_server_ip() const;

        void set_type_map(Dictionary Dic);
        Dictionary get_type_map();

        void _process(double p_delta) override;
        void _ready() override;
    };
}


#endif //GODOTPP_NETWORKMANAGER_H