// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Definition for a binary tree node.

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

// Forward declaration
int dfsHeight(TreeNode* root);

// check if a binary tree is height-balanced

bool isBalanced(TreeNode* root) {
    return dfsHeight(root)!= -1;
}

int dfsHeight(TreeNode* root) {
    if(root==NULL) return 0;

    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = dfsHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Creating the binary tree
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->left->left=new TreeNode(8);
    root->left->left->right=new TreeNode(9);


    if(isBalanced(root)) {
        cout << "The binary tree is height-balanced." << endl;
    } else {
        cout << "The binary tree is not height-balanced." << endl;
    }

    return 0;
}

