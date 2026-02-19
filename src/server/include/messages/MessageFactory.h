//
// MessageFactory.h
//

#ifndef GODOTPP_MESSAGEFACTORY_H
#define GODOTPP_MESSAGEFACTORY_H
#include <memory>

#include "BaseMessage.h"


class MessageFactory {
public:
    static std::unique_ptr<BaseMessage> CreateMessage(MessageType Type);

    static uint8_t SerializeMessage(BaseMessage& Message, std::vector<uint8_t>& buffer);
    static std::unique_ptr<BaseMessage> DeserializeMessage(std::vector<uint8_t>& buffer);
};


#endif //GODOTPP_MESSAGEFACTORY_H