project(command_pattern)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(command_pattern STATIC
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

set_target_properties(command_pattern PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(command_pattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
