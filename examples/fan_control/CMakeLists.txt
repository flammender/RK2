project(fan_control)

add_executable(fan_control example2.cpp)

set_target_properties(fan_control PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
