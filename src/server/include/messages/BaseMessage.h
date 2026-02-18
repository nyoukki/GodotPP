//
// BaseMessage.h
//

#ifndef GODOTPP_BASEMESSAGE_H
#define GODOTPP_BASEMESSAGE_H
#include <cstdint>
#include <vector>

enum class MessageType : uint8_t {
    RequestConnection = 0,
    //AcceptConnection = 1,
    Spawn = 2,
};

struct BaseMessage {
    virtual ~BaseMessage() = default;
    virtual MessageType GetType() const = 0;

    virtual uint8_t Serialize(std::vector<uint8_t>& buffer) const = 0;

    virtual void Deserialize(std::vector<uint8_t>& buffer, uint8_t size) = 0;
};

#endif //GODOTPP_BASEMESSAGE_H