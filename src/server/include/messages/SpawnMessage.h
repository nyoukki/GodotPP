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
        memcpy(buffer.data(), &NetworkId, sizeof(NetworkId));

        return sizeof(NetworkId);
    }

    void Deserialize(std::vector<uint8_t> &buffer, uint8_t size) override {
        if (buffer.size() >= sizeof(uint32_t))
            memcpy(&NetworkId, &buffer[0], sizeof(uint32_t));
    }
};

#endif //GODOTPP_SPAWNMESSAGE_H