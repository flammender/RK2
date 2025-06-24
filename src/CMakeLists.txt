project(src)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_executable(src
    main.cpp
)

target_link_libraries(src
    command_pattern
    Qt5::Core
)

set_target_properties(src PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
