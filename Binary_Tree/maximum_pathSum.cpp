// #include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
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

// Forward declaration
int maxPathDown(TreeNode* node, int& maxi);


// maximum path Sum

int maxPathSum(TreeNode* root) {
    int maxi=INT32_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int maxPathDown(TreeNode* node, int& maxi) {
    if (node == NULL) {
        return 0;
    }
    int leftMax = maxPathDown(node->left, maxi);
    int rightMax = maxPathDown(node->right, maxi);

    maxi = max(maxi,node->val + leftMax + rightMax);
    return max(0, node->val + max(leftMax, rightMax));  // zero for negative path sums
}

int main() {
    // Creating the binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;
    return 0;

}
