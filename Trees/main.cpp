#include <vector>

#include "BinaryTree.cpp"
#include <string>
#include <iostream>

int main()
{
    std::vector<std::vector<TreeNode<int> *>> listOfTrees = {{new TreeNode<int>(2), new TreeNode<int>(1), new TreeNode<int>(4), new TreeNode<int>(3), new TreeNode<int>(5), new TreeNode<int>(6), new TreeNode<int>(7)},
                                                             {new TreeNode<int>(1), new TreeNode<int>(2), new TreeNode<int>(3), new TreeNode<int>(4), new TreeNode<int>(5), new TreeNode<int>(6), new TreeNode<int>(7), new TreeNode<int>(8), new TreeNode<int>(9)},
                                                             {new TreeNode<int>(45), new TreeNode<int>(32), new TreeNode<int>(23), new TreeNode<int>(21), new TreeNode<int>(18), new TreeNode<int>(1)},
                                                             {new TreeNode<int>(5), new TreeNode<int>(3), new TreeNode<int>(4), new TreeNode<int>(1), new TreeNode<int>(2), new TreeNode<int>(6), new TreeNode<int>(7), new TreeNode<int>(8), new TreeNode<int>(9)},
                                                             {new TreeNode<int>(9), new TreeNode<int>(7), nullptr, nullptr, new TreeNode<int>(1), new TreeNode<int>(8), new TreeNode<int>(10), nullptr, new TreeNode<int>(12)}};

    int y = 1;
    for (const BinaryTree<int> tree : listOfTrees)
    {
        std::cout << y << ".\tBinary tree:\n";
        // DisplayTree(tree.root);
        std::cout << "\tDiameter of the tree: " << DiameterOfBinaryTree(tree.root) << "\n";
        std::cout << std::string(100, '-') << std::endl;
        y++;
    }


    y = 1;
    for (const BinaryTree<int> tree : listOfTrees)
    {
        
        std::cout << y << ".\tBinary tree:\n";
        // DisplayTree(tree.root);
        std::cout << "\tDiameter of the tree: " << MaxBranchLength(tree.root) << "\n";
        std::cout << std::string(100, '-') << std::endl;
        y++;
    }
}