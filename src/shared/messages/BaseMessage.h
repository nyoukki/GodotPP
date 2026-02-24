//
// BaseMessage.h
//

#ifndef GODOTPP_BASEMESSAGE_H
#define GODOTPP_BASEMESSAGE_H
#include <cstdint>
#include <vector>

enum class MessageType : uint8_t {
    Error = 0,
    RequestConnection = 1,
    //AcceptConnection = 2,
    Spawn = 3,
};

struct BaseMessage {
    virtual ~BaseMessage() = default;
    virtual MessageType GetType() const = 0;

    virtual uint8_t Serialize(std::vector<uint8_t>& buffer) const = 0;

    virtual void Deserialize(std::vector<uint8_t>::iterator buffer, uint8_t size) = 0;
};

#endif //GODOTPP_BASEMESSAGE_H