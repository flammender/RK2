cmake_minimum_required(VERSION 3.10)

project(CommandPatternProject CXX)

include(CPack)

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)
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
add_subdirectory(tests)
