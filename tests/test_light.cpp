#include "gtest/gtest.h"
#include "light.h"
#include <string>
#include <iostream>

class LightTestFixture : public ::testing::Test {
protected:
    Light light;

    void SetUp() override {
        light.Off();
        ::testing::internal::CaptureStdout();
        ::testing::internal::GetCapturedStdout();
    }
};

TEST_F(LightTestFixture, InitialStateIsOff) {
    ASSERT_FALSE(light.isOn());
}

TEST_F(LightTestFixture, TurnOnWorksAndPrintsCorrectly) {
    ::testing::internal::CaptureStdout();
    light.On();
    std::string output = ::testing::internal::GetCapturedStdout();

    ASSERT_TRUE(light.isOn());
    EXPECT_NE(output.find("Light is on"), std::string::npos);
}

TEST_F(LightTestFixture, TurnOffWorksAndPrintsCorrectly) {
    light.On();
    ASSERT_TRUE(light.isOn());

    ::testing::internal::CaptureStdout();
    light.Off();
    std::string output = ::testing::internal::GetCapturedStdout();

    ASSERT_FALSE(light.isOn());
    EXPECT_NE(output.find("Light is off"), std::string::npos);
}
