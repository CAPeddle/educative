#include <gtest/gtest.h>

#include "BinaryTree.cpp"

#include <climits>
#include <sstream>

class ReverseTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ReverseTest, Head)
{
    std::vector<std::vector<TreeNode<int> *>> listOfTrees = {{new TreeNode<int>(2), new TreeNode<int>(1), new TreeNode<int>(4), new TreeNode<int>(3), new TreeNode<int>(5), new TreeNode<int>(6), new TreeNode<int>(7)},
                                                             {new TreeNode<int>(1), new TreeNode<int>(2), new TreeNode<int>(3), new TreeNode<int>(4), new TreeNode<int>(5), new TreeNode<int>(6), new TreeNode<int>(7), new TreeNode<int>(8), new TreeNode<int>(9)},
                                                             {new TreeNode<int>(45), new TreeNode<int>(32), new TreeNode<int>(23), new TreeNode<int>(21), new TreeNode<int>(18), new TreeNode<int>(1)},
                                                             {new TreeNode<int>(5), new TreeNode<int>(3), new TreeNode<int>(4), new TreeNode<int>(1), new TreeNode<int>(2), new TreeNode<int>(6), new TreeNode<int>(7), new TreeNode<int>(8), new TreeNode<int>(9)},
                                                             {new TreeNode<int>(9), new TreeNode<int>(7), nullptr, nullptr, new TreeNode<int>(1), new TreeNode<int>(8), new TreeNode<int>(10), nullptr, new TreeNode<int>(12)}};

    int y = 1;
    for (const BinaryTree<int> tree : listOfTrees)
    {
        switch (y)
        {
        case 1:
            EXPECT_EQ(4, DiameterOfBinaryTree(tree.root));
            break;
        case 2:
            EXPECT_EQ(5, DiameterOfBinaryTree(tree.root));
            break;
        case 3:
            EXPECT_EQ(4, DiameterOfBinaryTree(tree.root));
            break;
        case 4:
            EXPECT_EQ(5, DiameterOfBinaryTree(tree.root));
            break;
        case 5:
            EXPECT_EQ(4, DiameterOfBinaryTree(tree.root));
            break;

        default:
            break;
        }
        y++;
    }
}
