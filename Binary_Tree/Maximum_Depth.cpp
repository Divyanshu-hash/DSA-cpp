// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

// Definition of TreeNode

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Maximum Depth of Binary Tree

int maxDepth(TreeNode* root) {
    if (root==NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    /// Creating the binary tree
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int result = maxDepth(root);

    // Printing result
    cout << "Maximum Depth of the Binary Tree: " << result << endl;
    return 0;

}