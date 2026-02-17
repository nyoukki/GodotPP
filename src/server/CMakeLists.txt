add_executable(GodotPPServer
    src/main.cpp
        src/LinkingContext.cpp
        include/LinkingContext.h
)

target_link_libraries(GodotPPServer PRIVATE
        snl
        EnTT::EnTT)