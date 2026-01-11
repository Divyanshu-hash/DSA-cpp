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

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> topNode;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int line = p.second;
        if(topNode.find(line) == topNode.end()){
            topNode[line] = node->val;
        }
        if(node->left){
            q.push({node->left, line - 1});
        }
        if(node->right){
            q.push({node->right, line + 1});
        }
    }
    for(auto p : topNode){
        ans.push_back(p.second);
    }
    return ans;
}
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = topView(root);
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}