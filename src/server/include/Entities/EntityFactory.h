//
// EntityFactory.h
//

#ifndef GODOTPP_ENTITYFACTORY_H
#define GODOTPP_ENTITYFACTORY_H
#include <entt/entity/registry.hpp>


class LinkingContext;

class EntityFactory {

public:
    static void RegisterAll(LinkingContext Context);
};


#endif //GODOTPP_ENTITYFACTORY_H