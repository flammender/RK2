target_include_directories(CommandPatternLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(CommandPatternLib STATIC
    command.cpp
    command.h
    light.cpp
    light.h
    lightoffcommand.cpp
    lightoffcommand.h
    lightoncommand.cpp
    lightoncommand.h
    remotecontrol.cpp
    remotecontrol.h
)


)
