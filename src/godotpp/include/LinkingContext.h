//
// LinkingContext.h
//

#ifndef GODOTPP_LINKINGCONTEXT_H
#define GODOTPP_LINKINGCONTEXT_H
#include <functional>
#include <godot_cpp/classes/scene_tree.hpp>

namespace godot {
    class LinkingContext {

    public:
        struct ObjectContext {
            uint32_t NetworkId;
            Node* Entity;
        };

    private:
        HashMap<uint32_t, ObjectContext> network_to_local_map;
        HashMap<uint32_t, Ref<PackedScene>> type_map;

    public:
        ObjectContext GetFromNetwork(uint32_t NetworkId);

        void RegisterType(uint32_t TypeId, Ref<PackedScene> Scene);
        ObjectContext CreateFromId(uint32_t TypeId, uint32_t NetworkId, Node* Parent);
    };
}
#endif //GODOTPP_LINKINGCONTEXT_H