//
// LinkingContext.h
//

#ifndef GODOTPP_LINKINGCONTEXT_H
#define GODOTPP_LINKINGCONTEXT_H
#include "entt/entt.hpp"

typedef std::function<entt::entity(entt::registry&)> CreationLambda;

class LinkingContext {

private:
    struct ObjectContext {
        uint32_t NetworkId;
        entt::entity local_entity;
    };

    std::unordered_map<uint32_t, ObjectContext> network_to_local_map;
    std::unordered_map<uint32_t, CreationLambda> type_map;

    uint32_t IdCounter = 100;

public:
    // Objects
    ObjectContext GetFromNetwork(uint32_t NetworkId);

    // Type
    void RegisterType(uint32_t TypeId, const CreationLambda &CreatorFunc);
    ObjectContext CreateFromTypeId(uint32_t TypeId, entt::registry& reg);
};


#endif //GODOTPP_LINKINGCONTEXT_H