add_executable(GodotPPServer
    src/main.cpp
        src/LinkingContext.cpp
        include/LinkingContext.h
        include/messages/BaseMessage.h
        src/messages/MessageFactory.cpp
        include/messages/MessageFactory.h
        include/messages/RequestConnectionMessage.h
        include/messages/SpawnMessage.h
)

target_link_libraries(GodotPPServer PRIVATE
        snl
        EnTT::EnTT)