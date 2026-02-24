//
// LinkingContext.cpp
//

#include "../include/LinkingContext.h"

#include <iostream>

LinkingContext::ObjectContext LinkingContext::GetFromNetwork(const uint32_t NetworkId) {
    if (network_to_local_map.find(NetworkId) != network_to_local_map.end()) {
        return network_to_local_map[NetworkId];
    }
    std::cerr << "Failed to find entity with ID" << NetworkId << std::endl;
    return {0, entt::null};
}

void LinkingContext::RegisterType(const EntityType TypeId, const CreationLambda &CreatorFunc) {
    type_map[TypeId] = CreatorFunc;
}

LinkingContext::ObjectContext LinkingContext::CreateFromTypeId(const EntityType TypeId, entt::registry &reg) {
    if (type_map.find(TypeId) != type_map.end()) {
        const entt::entity new_entity = type_map[TypeId](reg);
        const LinkingContext::ObjectContext new_object = {++IdCounter, new_entity};
        network_to_local_map[IdCounter] = new_object;
    }
    std::cerr << "Failed to create entity of type" << static_cast<uint32_t>(TypeId) << std::endl;
    return {0, entt::null};
}
