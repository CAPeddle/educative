#include <gtest/gtest.h>

#include <unordered_map>

#include "Palindrome.h"

class PalindromeTest : public ::testing::Test {
protected:
    Palindrome* logger;

    void SetUp() override {
        // Using 10 second time limit
        logger = new Palindrome();
    }

    void TearDown() override {
        delete logger;
    }
};

TEST_F(PalindromeTest, TestMessageSequence) {
    // Test sequence from provided example
    EXPECT_TRUE(logger->PermutePalindrome("ababc"));
    EXPECT_TRUE(logger->PermutePalindrome("abab"));
    EXPECT_FALSE(logger->PermutePalindrome("peas"));
    EXPECT_TRUE(logger->PermutePalindrome("racecar"));
    EXPECT_FALSE(logger->PermutePalindrome("code"));
    EXPECT_TRUE(logger->PermutePalindrome("baefeab"));
}
