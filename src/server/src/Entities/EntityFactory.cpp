//
// EntityFactory.cpp
//

#include "../../include/Entities/EntityFactory.h"

#include "../../include/LinkingContext.h"
#include "../../include/Entities/PlayerFactory.h"

void EntityFactory::RegisterAll(LinkingContext Context) {
    Context.RegisterType(PlayerFactory::TypeId, &PlayerFactory::Create);
}
