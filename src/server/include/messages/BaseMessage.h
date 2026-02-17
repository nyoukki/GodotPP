//
// BaseMessage.h
//

#ifndef GODOTPP_BASEMESSAGE_H
#define GODOTPP_BASEMESSAGE_H
#include <cstdint>

struct BaseMessage {
    uint8_t Type;
    uint8_t Size;
    uint8_t* Data;
};

#endif //GODOTPP_BASEMESSAGE_H