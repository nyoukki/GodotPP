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
};


#endif //GODOTPP_MESSAGEFACTORY_H