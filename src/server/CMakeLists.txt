add_executable(GodotPPServer
    src/main.cpp
        src/LinkingContext.cpp
        include/LinkingContext.h
        include/messages/BaseMessage.h
        src/messages/MessageFactory.cpp
        include/messages/MessageFactory.h
        include/messages/RequestConnectionMessage.h
        include/messages/SpawnMessage.h
        src/Components/Transform2DComponent.cpp
        include/Components/Transform2DComponent.h
        src/Entities/PlayerFactory.cpp
        include/Entities/PlayerFactory.h
        src/Entities/EntityFactory.cpp
        include/Entities/EntityFactory.h
        src/NetworkManager.cpp
        include/NetworkManager.h
)

target_link_libraries(GodotPPServer PRIVATE
        snl
        EnTT::EnTT)