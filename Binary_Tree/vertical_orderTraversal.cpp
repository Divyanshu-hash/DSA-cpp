#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(temp->val);
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto p:nodes){
        vector<int> col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    // Example usage:
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);

    for(const auto& col : result){
        for(int val : col){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}