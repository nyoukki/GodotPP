add_executable(GodotPPServer
    src/main.cpp
        src/LinkingContext.cpp
        include/LinkingContext.h
        ../shared/messages/BaseMessage.h
        ../shared/messages/MessageFactory.cpp
        ../shared/messages/MessageFactory.h
        ../shared/messages/RequestConnectionMessage.h
        ../shared/messages/SpawnMessage.h
        ../shared/messages/ErrorMessage.h
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