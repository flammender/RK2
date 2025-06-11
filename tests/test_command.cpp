#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "command.h"

class MockCommand : public Command {
public:
    MOCK_METHOD(void, Execute, (), (override));
};

TEST(CommandTest, ExecuteMethodIsVirtual) {
    MockCommand mockCmd;
}

TEST(CommandTest, DerivedCommandCanBeExecuted) {
    class ConcreteCommand : public Command {
    public:
        bool executed = false;
        void Execute() override {
            executed = true; 
        }
    };

    ConcreteCommand cmd;
    ASSERT_FALSE(cmd.executed);

    cmd.Execute();
    ASSERT_TRUE(cmd.executed);
}
