#include <gtest/gtest.h>

#include "NoOfIslands.h"

class NoOfIslandsTest : public ::testing::Test {
protected:
    NoOfIslands* islands;

    void SetUp() override {
        // Using 10 second time limit
        islands = new NoOfIslands();
    }

    void TearDown() override {
        delete islands;
    }
};

TEST_F(NoOfIslandsTest, TestMessageSequence) {
    
    std::vector<std::vector<std::string>> matrix = {
        {"x", "x", ".", ".", ".", "."},
        {"x", "x", ".", ".", ".", "."},
        {".", ".", "x", ".", ".", "."},
        {"x", ".", ".", "x", "x", "."},
        {"x", ".", "x", ".", "x", "."},
        {"x", "x", "x", ".", ".", "."}
    };
    EXPECT_EQ(4, NoOfIslands::countIslands(matrix));


    std::vector<std::vector<std::string>> matrix2 = {
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."}
    };
    EXPECT_EQ(0, NoOfIslands::countIslands(matrix2));

    std::vector<std::vector<std::string>> matrix3 = {
        {"x", ".", ".", ".", ".", "."},
        {".", "x", ".", ".", ".", "."},
        {".", ".", "x", ".", ".", "."},
        {".", ".", ".", "x", ".", "."},
        {".", ".", ".", ".", "x", "."},
        {".", ".", ".", ".", ".", "x"}
    };
    EXPECT_EQ(6, NoOfIslands::countIslands(matrix3));

    std::vector<std::vector<std::string>> matrix4 = {
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"}
    };
    EXPECT_EQ(1, NoOfIslands::countIslands(matrix4));


    std::vector<std::vector<std::string>> matrix5 = {
        {"x", ".", "x", "x", "x", "."},
        {"x", ".", ".", ".", "x", "."},
        {"x", ".", "x", ".", "x", "x"},
        {"x", "x", "x", ".", "x", "."},
        {".", ".", ".", "x", "x", "."},
        {".", ".", ".", ".", ".", "."}
    };

    EXPECT_EQ(2, NoOfIslands::countIslands(matrix5));
}
