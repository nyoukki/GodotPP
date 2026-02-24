//
// Player.h
//

#ifndef GODOTPP_PLAYER_H
#define GODOTPP_PLAYER_H
#include <cstdint>
#include <entt/entity/registry.hpp>

#include "../LinkingContext.h"


class PlayerFactory {

public:
    const static EntityType TypeId = EntityType::Player;
    static entt::entity Create(entt::registry& reg);
};


#endif //GODOTPP_PLAYER_H