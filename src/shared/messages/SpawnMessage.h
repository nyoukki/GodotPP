//
// SpawnMessage.h
//

#ifndef GODOTPP_SPAWNMESSAGE_H
#define GODOTPP_SPAWNMESSAGE_H
#include <cstring>

#include "BaseMessage.h"

struct SpawnMessage : BaseMessage {
    uint32_t NetworkId;
    uint32_t TypeId;

    MessageType GetType() const override {
        return MessageType::Spawn;
    }

    uint8_t Serialize(std::vector<uint8_t>& buffer) const override {
        for (int i=0; i<sizeof(NetworkId); i++) {
            buffer.push_back((NetworkId >> (8 * i)) & 0xFF);
        }
        for (int i=0; i<sizeof(TypeId); i++) {
            buffer.push_back((TypeId >> (8 * i)) & 0xFF);
        }

        return sizeof(NetworkId) + sizeof(TypeId);
    }

    void Deserialize(std::vector<uint8_t>::iterator buffer, uint8_t size) override {
        if (size >= 2 * sizeof(uint32_t)) {
            size_t offset = 0;
            memcpy(&NetworkId, &(*buffer), sizeof(uint32_t));
            offset += sizeof(uint32_t);
            memcpy(&TypeId, &*(buffer + offset), sizeof(uint32_t));
        }
    }
};

#endif //GODOTPP_SPAWNMESSAGE_H