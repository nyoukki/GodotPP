//
// HandshakeMessage.h
//

#ifndef GODOTPP_HANDSHAKEMESSAGE_H
#define GODOTPP_HANDSHAKEMESSAGE_H
#include <string>

#include "BaseMessage.h"

struct RequestConnectionMessage : BaseMessage {

    MessageType GetType() const override {
        return MessageType::RequestConnection;
    }

    uint8_t Serialize(std::vector<uint8_t>& buffer) const override {
        // No data
        return 0;
    }

    void Deserialize(std::vector<uint8_t>::iterator buffer, uint8_t size) override {
        // No data
    }

};

#endif //GODOTPP_HANDSHAKEMESSAGE_H