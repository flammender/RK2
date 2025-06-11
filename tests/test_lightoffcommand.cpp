#include "gtest/gtest.h"
#include "lightoffcommand.h"
#include "light.h"
#include <string>

TEST(LightOffCommandTest, ExecuteTurnsLightOffAndPrintsCorrectly) {
    Light light;
    light.On();
    ASSERT_TRUE(light.isOn());

    LightOffCommand lightOff(&light);

    ::testing::internal::CaptureStdout();
    lightOff.Execute();
    std::string output = ::testing::internal::GetCapturedStdout();

    ASSERT_FALSE(light.isOn());
    EXPECT_NE(output.find("Light is off"), std::string::npos);
}
