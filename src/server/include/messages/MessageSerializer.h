//
// MessageSerializer.h
//

#ifndef GODOTPP_MESSAGESERIALIZER_H
#define GODOTPP_MESSAGESERIALIZER_H
#include "BaseMessage.h"


class MessageSerializer {
    static BaseMessage Read(uint8_t* bytes);

    static void Serialize(BaseMessage Msg, uint8_t* Buffer);
};


#endif //GODOTPP_MESSAGESERIALIZER_H