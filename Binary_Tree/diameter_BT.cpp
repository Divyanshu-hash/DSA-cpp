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

    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};


// Forward declaration
int dfsHeight(TreeNode* root,int& diameter);


// Diameter Of Binary Tree
int diameter(TreeNode* root){
    int diameter=0;
    dfsHeight(root, diameter);
    return diameter;
}

int dfsHeight(TreeNode* root,int& diameter){
    if(root==NULL) return 0;
    int leftHeight=dfsHeight(root->left,diameter);
    int rightHeight=dfsHeight(root->right,diameter);
    diameter=max(diameter,leftHeight+rightHeight);
    return max(leftHeight,rightHeight)+1;
}

int main() {
    // Creating the binary tree
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->right->right->left=new TreeNode(8);
    root->right->left->left=new TreeNode(9);
    root->right->right->right=new TreeNode(10);
    root->right->left->left->left=new TreeNode(11);
    root->right->left->left->left=new TreeNode(12);



    cout << "Diameter of the binary tree is: " << diameter(root) << endl;

    return 0;
}