//
// MessageFactory.cpp
//

#include "MessageFactory.h"

#include "RequestConnectionMessage.h"
#include "SpawnMessage.h"

std::unique_ptr<BaseMessage> MessageFactory::CreateMessage(const MessageType Type) {
    switch (Type) {
        case MessageType::RequestConnection:
            return std::make_unique<RequestConnectionMessage>();
        case MessageType::Spawn:
            return std::make_unique<SpawnMessage>();
    }
}

uint8_t MessageFactory::SerializeMessage(BaseMessage &Message, std::vector<uint8_t> &buffer) {

    buffer.clear();

    // Type
    buffer.push_back(static_cast<uint8_t>(Message.GetType()));

    // Reserving room for the size
    buffer.push_back(0);

    // Data
    Message.Serialize(buffer);

    // Size
    uint8_t Size = static_cast<uint8_t>(buffer.size());
    buffer[1] = Size;

    return Size;
}

std::unique_ptr<BaseMessage> MessageFactory::DeserializeMessage(std::vector<uint8_t> &buffer) {
    MessageType Type = static_cast<MessageType>(buffer[0]);
    uint8_t Size = buffer[1];
    std::unique_ptr<BaseMessage> Message = CreateMessage(Type);

    Message->Deserialize(buffer.begin() + 2, Size);

    return Message;
}
