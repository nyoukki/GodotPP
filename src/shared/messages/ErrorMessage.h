//
// ErrorMessage.h
//

#ifndef GODOTPP_ERRORMESSAGE_H
#define GODOTPP_ERRORMESSAGE_H
#include <string>

#include "BaseMessage.h"

struct ErrorMessage : BaseMessage {

    MessageType GetType() const override {
        return MessageType::Error;
    }

    uint8_t Serialize(std::vector<uint8_t>& buffer) const override {
        // No data
        return 0;
    }

    void Deserialize(std::vector<uint8_t>::iterator buffer, uint8_t size) override {
        // No data
    }

};

#endif //GODOTPP_ERRORMESSAGE_H