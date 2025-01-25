#include <gtest/gtest.h>

#include <unordered_map>

#include "RateLimiter.h"

class RequestLoggerTest : public ::testing::Test {
protected:
    RequestLogger* logger;

    void SetUp() override {
        // Using 10 second time limit
        logger = new RequestLogger(10);
    }

    void TearDown() override {
        delete logger;
    }
};

//[[1,"good morning"],[5,"good morning"],[9,"i need coffee"],[10,"hello world"],[11,"good morning"],[15,"i need coffee"],
//Expected [true,false,true,true,true,false,true,true]

TEST_F(RequestLoggerTest, TestMessageSequence) {
    // Test sequence from provided example
    EXPECT_TRUE(logger->MessageRequestDecision(1, "good morning"));
    EXPECT_FALSE(logger->MessageRequestDecision(5, "good morning"));
    EXPECT_TRUE(logger->MessageRequestDecision(9, "i need coffee"));
    EXPECT_TRUE(logger->MessageRequestDecision(10, "hello world"));
    EXPECT_TRUE(logger->MessageRequestDecision(11, "good morning"));
    EXPECT_FALSE(logger->MessageRequestDecision(15, "i need coffee"));
}

TEST_F(RequestLoggerTest, TestTimeLimit) {
    EXPECT_TRUE(logger->MessageRequestDecision(1, "test message"));
    EXPECT_FALSE(logger->MessageRequestDecision(5, "test message"));
    EXPECT_TRUE(logger->MessageRequestDecision(12, "test message")); // After time limit
}

TEST_F(RequestLoggerTest, TestDifferentMessages) {
    EXPECT_TRUE(logger->MessageRequestDecision(1, "message1"));
    EXPECT_TRUE(logger->MessageRequestDecision(1, "message2"));
    EXPECT_FALSE(logger->MessageRequestDecision(2, "message1"));
}


TEST_F(RequestLoggerTest, TestCase2) {
    EXPECT_TRUE(logger->MessageRequestDecision(1, "good morning"));
    EXPECT_TRUE(logger->MessageRequestDecision(5, "message2"));
    EXPECT_FALSE(logger->MessageRequestDecision(6, "good morning"));
    EXPECT_FALSE(logger->MessageRequestDecision(7, "good morning"));
    EXPECT_TRUE(logger->MessageRequestDecision(15, "hello world"));
}