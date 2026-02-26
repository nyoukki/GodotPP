//
// LinkingContext.cpp
//

#include "LinkingContext.h"

#include <string>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

void LinkingContext::RegisterType(uint32_t TypeId, Ref<PackedScene> Scene) {
    type_map[TypeId] = Scene;
    print_line("Type ", TypeId, " registered successfully.");
}

LinkingContext::ObjectContext LinkingContext::CreateFromId(uint32_t TypeId, uint32_t NetworkId, Node* Parent) {
    print_line("Type: ", TypeId);
    if (type_map.find(TypeId) == type_map.end()) {
        print_error("Failed to create entity.");
        return {NetworkId, nullptr};
    }

    Node* new_entity = type_map[TypeId]->instantiate();
    ObjectContext new_object = {NetworkId, new_entity};
    network_to_local_map[NetworkId] = new_object;

    Parent->add_child(new_entity);

    return new_object;
}
