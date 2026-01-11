#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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

vector<vector<int>> ZigZag(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    bool LeftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            int index=LeftToRight?i:(size-1-i);
            ans[index]=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        LeftToRight=!LeftToRight;
        result.push_back(ans);
    }
    return result;
}

int main(){

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(8);
    root->right->left=new TreeNode(9);

    vector<vector<int>> result=ZigZag(root);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}