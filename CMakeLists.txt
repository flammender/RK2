cmake_minimum_required(VERSION 3.10)

project(CommandPatternProject)

include(CPack)

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A C++ project demonstrating the Command Pattern.")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/flammender/RK2")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")

set(CPACK_GENERATOR "DEB")

set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "${CPACK_PACKAGE_HOMEPAGE_URL}")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")

add_subdirectory(command_pattern)
add_subdirectory(src)
add_subdirectory(examples/fan_control)
enable_testing()
#add_subdirectory(tests)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  add_executable(LightTests tests/test_light.cpp)
  add_executable(CommandTests tests/test_command.cpp)
  add_executable(LightOnCommandTests tests/test_lightoncommand.cpp)
  add_executable(LightOffCommandTests tests/test_lightoffcommand.cpp)
  add_executable(RemoteControlTests tests/test_remotecontrol.cpp)
  target_link_libraries(LightTests CommandTests LightOnCommandTests LightOffCommandTests RemoteControlTests gtest_main command_pattern src)
  add_test(NAME LightTest COMMAND LightTests)
  add_test(NAME CommandTest COMMAND CommandTests)
  add_test(NAME LightOnCommandTest COMMAND LightOnCommandTests)
  add_test(NAME LightOffCommandTest COMMAND LightOffCommandTests)
  add_test(NAME RemoteControlTest COMMAND RemoteControlTests)
endif()

set(CPACK_GENERATOR "DEB")
