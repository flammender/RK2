#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "remotecontrol.h"
#include "command.h"

class MockCommand : public Command {
public:
    MOCK_METHOD(void, Execute, (), (override));
};

TEST(RemoteControlTest, ButtonPushedExecutesAssignedCommand) {
    RemoteControl remote;
    MockCommand mockCommand;

    EXPECT_CALL(mockCommand, Execute())
        .Times(1);

    remote.SetCommand(&mockCommand);
    remote.ButtonPushed();
}

TEST(RemoteControlTest, SetCommandAssignsCommand) {
    RemoteControl remote;
    MockCommand mockCommand1;
    MockCommand mockCommand2;

    EXPECT_CALL(mockCommand1, Execute()).Times(0);
    EXPECT_CALL(mockCommand2, Execute()).Times(0);

    remote.SetCommand(&mockCommand1);
    EXPECT_CALL(mockCommand1, Execute()).Times(1);
    remote.ButtonPushed();

    remote.SetCommand(&mockCommand2);
    EXPECT_CALL(mockCommand2, Execute()).Times(1);
    remote.ButtonPushed();
}
