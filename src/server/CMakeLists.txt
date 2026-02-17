add_executable(GodotPPServer
    src/main.cpp
        src/LinkingContext.cpp
        include/LinkingContext.h
        include/messages/BaseMessage.h
        src/messages/MessageSerializer.cpp
        include/messages/MessageSerializer.h
)

target_link_libraries(GodotPPServer PRIVATE
        snl
        EnTT::EnTT)