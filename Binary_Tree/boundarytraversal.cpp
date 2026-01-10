#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* node) {
    return !node->left && !node->right;
}

void addLeftBoundary(TreeNode* node, vector<int>& res) {
    TreeNode* cur = node;
    while (cur) {
        if (!isLeaf(cur))
            res.push_back(cur->val);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addLeaves(TreeNode* node, vector<int>& res) {
    if (!node) return;
    if (isLeaf(node)) {
        res.push_back(node->val);
        return;
    }
    addLeaves(node->left, res);
    addLeaves(node->right, res);
}

void addRightBoundary(TreeNode* node, vector<int>& res) {
    vector<int> temp;
    TreeNode* cur = node;
    while (cur) {
        if (!isLeaf(cur))
            temp.push_back(cur->val);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    res.push_back(root->val);

    addLeftBoundary(root->left, res);
    addLeaves(root->left, res);
    addLeaves(root->right, res);
    addRightBoundary(root->right, res);

    return res;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    root->right->right = new TreeNode(6);

    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}