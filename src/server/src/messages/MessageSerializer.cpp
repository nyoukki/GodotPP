//
// MessageSerializer.cpp
//

#include "../../include/messages/MessageSerializer.h"

BaseMessage MessageSerializer::Read(uint8_t *bytes) {
    BaseMessage Msg{};
    Msg.Type = bytes[0];
    Msg.Size = bytes[1];

    uint8_t* Data = bytes + 2;
    Msg.Data = Data;

    return Msg;
}

void MessageSerializer::Serialize(const BaseMessage Msg, uint8_t* Buffer) {
    Buffer[0] = Msg.Type;
    Buffer[1] = Msg.Size;

    for (uint8_t i=0; i<Msg.Size; i++) {
        Buffer[i+2] = Msg.Data[i];
    }
}
