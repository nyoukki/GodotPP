//
// Player.cpp
//

#include "../../include/Entities/PlayerFactory.h"

#include "../../include/Components/Transform2DComponent.h"


entt::entity PlayerFactory::Create(entt::registry& reg) {
    entt::entity NewPlayer = reg.create();
    reg.emplace<Transform2DComponent>(NewPlayer);
    return NewPlayer;
}
