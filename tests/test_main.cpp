#include <gtest/gtest.h>

#include "../src/hello-world/utils.cpp"

namespace {

// The fixture for testing class Foo.
class HelloWorldTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  HelloWorldTest() {
     // You can do set-up work for each test here.
  }

  ~HelloWorldTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suit
};


TEST(HelloWorldTest, VersionTest) {
    ASSERT_EQ(version, "0.0.1") << "Version not updated!";
}

}  // namespace



int main_test(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
