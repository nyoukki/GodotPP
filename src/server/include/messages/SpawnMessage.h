//
// SpawnMessage.h
//

#ifndef GODOTPP_SPAWNMESSAGE_H
#define GODOTPP_SPAWNMESSAGE_H
#include <cstring>

#include "BaseMessage.h"

struct SpawnMessage : BaseMessage {
    uint32_t NetworkId;

    MessageType GetType() const override {
        return MessageType::Spawn;
    }

    uint8_t Serialize(std::vector<uint8_t>& buffer) const override {
        for (int i=0; i<sizeof(uint32_t); i++) {
            buffer.push_back((NetworkId >> (8 * i)) & 0xFF);
        }

        return sizeof(NetworkId);
    }

    void Deserialize(std::vector<uint8_t>::iterator buffer, uint8_t size) override {
        if (size >= sizeof(uint32_t))
            memcpy(&NetworkId, &(*buffer), sizeof(uint32_t));
    }
};

#endif //GODOTPP_SPAWNMESSAGE_H