//
// LinkingContext.h
//

#ifndef GODOTPP_LINKINGCONTEXT_H
#define GODOTPP_LINKINGCONTEXT_H
#include "entt/entt.hpp"

typedef std::function<entt::entity(entt::registry&)> CreationLambda;

enum class EntityType : uint32_t {
    Error = 0,
    Player = 1,
};

class LinkingContext {

public:
    struct ObjectContext {
        uint32_t NetworkId;
        entt::entity local_entity;
        EntityType Type;
    };

private:
    std::unordered_map<uint32_t, ObjectContext> network_to_local_map;
    std::unordered_map<EntityType, CreationLambda> type_map;

    uint32_t IdCounter = 99;

public:
    // Objects
    ObjectContext GetFromNetwork(uint32_t NetworkId);
    std::vector<ObjectContext> GetAllObjects();

    // Type
    void RegisterType(EntityType TypeId, const CreationLambda &CreatorFunc);
    ObjectContext CreateFromTypeId(EntityType TypeId, entt::registry& reg);
};


#endif //GODOTPP_LINKINGCONTEXT_H