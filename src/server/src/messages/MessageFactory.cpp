//
// MessageFactory.cpp
//

#include "../../include/messages/MessageFactory.h"

#include "../../include/messages/RequestConnectionMessage.h"
#include "../../include/messages/SpawnMessage.h"

std::unique_ptr<BaseMessage> MessageFactory::CreateMessage(const MessageType Type) {
    switch (Type) {
        case MessageType::RequestConnection:
            return std::make_unique<RequestConnectionMessage>();
        case MessageType::Spawn:
            return std::make_unique<SpawnMessage>();
    }
}
