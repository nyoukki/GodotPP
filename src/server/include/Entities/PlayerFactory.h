//
// Player.h
//

#ifndef GODOTPP_PLAYER_H
#define GODOTPP_PLAYER_H
#include <cstdint>
#include <entt/entity/registry.hpp>


class PlayerFactory {

public:
    const static uint32_t TypeId = 1;
    static entt::entity Create(entt::registry& reg);
};


#endif //GODOTPP_PLAYER_H