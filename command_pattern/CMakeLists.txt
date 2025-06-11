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

set_target_properties(CommandPatternLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
