include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

target_include_directories(gtest_main PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../command_pattern
)

add_executable(LightTests test_light.cpp)
add_executable(CommandTests test_command.cpp)
add_executable(LightOnCommandTests test_lightoncommand.cpp)
add_executable(LightOffCommandTests test_lightoffcommand.cpp)
add_executable(RemoteControlTests test_remotecontrol.cpp)

target_link_libraries(LightTests gtest_main CommandPatternLib)
target_link_libraries(CommandTests gtest_main CommandPatternLib)
target_link_libraries(LightOnCommandTests gtest_main CommandPatternLib)
target_link_libraries(LightOffCommandTests gtest_main CommandPatternLib)
target_link_libraries(RemoteControlTests gtest_main CommandPatternLib)

add_test(NAME LightTest COMMAND LightTests)
add_test(NAME CommandTest COMMAND CommandTests)
add_test(NAME LightOnCommandTest COMMAND LightOnCommandTests)
add_test(NAME LightOffCommandTest COMMAND LightOffCommandTests)
add_test(NAME RemoteControlTest COMMAND RemoteControlTests)
