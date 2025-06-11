project(FanControlExample CXX)

add_executable(FanControlExample example2.cpp)

set_target_properties(FanControlExample PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
