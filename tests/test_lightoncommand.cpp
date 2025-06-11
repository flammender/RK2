#include "gtest/gtest.h"
#include "lightoncommand.h"
#include "light.h"
#include <string>

TEST(LightOnCommandTest, ExecuteTurnsLightOnAndPrintsCorrectly) {
    Light light;
    light.Off();
    ASSERT_FALSE(light.isOn());

    LightOnCommand lightOn(&light);

    ::testing::internal::CaptureStdout();
    lightOn.Execute();
    std::string output = ::testing::internal::GetCapturedStdout();

    ASSERT_TRUE(light.isOn());
    EXPECT_NE(output.find("Light is on"), std::string::npos);
}
