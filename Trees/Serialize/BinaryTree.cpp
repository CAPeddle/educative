#pragma once
#include <string>
#include <vector>
#include <queue>
#include "TreeNode.cpp"

/*
FUNCTION preorderTraversal(node):
  IF node is null:
    RETURN
  
  # Visit the root node
  visit(node)
  
  # Recursively traverse the left subtree
  preorderTraversal(node.left)
  
  # Recursively traverse the right subtree
  preorderTraversal(node.right)
*/

// Function to serialize tree into list of integers.
std::vector<std::string> Serialize(TreeNode<int> *root){
    
    
    // Replace this placeholder return statement with your code
    return {""};
}

// Function to deserialize integer list into a binary tree.
TreeNode<int> *Deserialize(std::vector<std::string> &stream){
    
    // Replace this placeholder return statement with your code
    return nullptr;
}

int DiameterOfBinaryTreeHelper(TreeNode<int> *root, int &diameter)
{
    if (root == nullptr) return 0;

    auto leftBranchLength = DiameterOfBinaryTreeHelper(root->left, diameter);
    auto rightBranchLength = DiameterOfBinaryTreeHelper(root->right, diameter);
    
    diameter = std::max(diameter , leftBranchLength + rightBranchLength);

    return std::max(leftBranchLength, rightBranchLength) + 1;
}

// DiameterOfBinaryTree returns the diameter of tree
int DiameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    DiameterOfBinaryTreeHelper(root, diameter);
    // Replace this placeholder return statement with your code
    return diameter;
}

template<class T>
class BinaryTree {
public:
    TreeNode<T>* root;

    BinaryTree<T>(const std::vector<TreeNode<T>*>& ListOfNodes) : root(createBinaryTree(ListOfNodes)){}

    TreeNode<T>* createBinaryTree(const std::vector<TreeNode<T>*>& ListOfNodes) {
        if (ListOfNodes.empty()) {
            return nullptr;
        }

        // Create the root node of the binary tree
        TreeNode<T>* root = new TreeNode<T>(ListOfNodes[0]->data);

        // Create a queue and add the root node to it
        std::queue<TreeNode<T>*> q;
        q.push(root);

        // Start iterating over the vector of nodes starting from the second node
        int i = 1;
        while (i < ListOfNodes.size()) {
            // Get the next node from the queue
            TreeNode<T>* curr = q.front();
            q.pop();

            // If the node is not null, create a new TreeNode object for its left child,
            // set it as the left child of the current node, and add it to the queue
            if (ListOfNodes[i] != nullptr) {
                curr->left = new TreeNode<T>(ListOfNodes[i]->data);
                q.push(curr->left);
            }

            i++;

            // If there are more nodes in the vector and the next node is not null,
            // create a new TreeNode object for its right child, set it as the right child
            // of the current node, and add it to the queue
            if (i < ListOfNodes.size() && ListOfNodes[i] != nullptr) {
                curr->right = new TreeNode<T>(ListOfNodes[i]->data);
                q.push(curr->right);
            }

            i++;
        }

        // Return the root of the binary tree
        return root;
    }
};
