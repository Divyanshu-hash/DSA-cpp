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


// sameTree

bool isSameTree(TreeNode* p, TreeNode* q) {
    
    if (p == NULL && q == NULL) {
        return true;
    }
    
    if (p == NULL || q == NULL) {
        return false;
    }
    
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p=new TreeNode(1);
    p->left=new TreeNode(2);
    p->right=new TreeNode(3);
    p->right->left=new TreeNode(4);
    p->right->right=new TreeNode(5);

    TreeNode* q=new TreeNode(1);
    q->left=new TreeNode(2);
    q->right=new TreeNode(3);
    q->right->left=new TreeNode(4);
    q->right->right=new TreeNode(5);

    if(isSameTree(p,q)){
        cout<<"The two trees are identical."<<endl;
    }
    else{
        cout<<"The two trees are not identical."<<endl;
    }
    return 0;
}
