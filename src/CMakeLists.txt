find_package(Qt5 COMPONENTS Core REQUIRED)

target_include_directories(CommandPatternApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CommandPatternApp
    main.cpp
)

target_link_libraries(CommandPatternApp
    CommandPatternLib
    Qt5::Core
)

set_target_properties(CommandPatternApp PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
