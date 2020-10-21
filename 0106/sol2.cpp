#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTreeRe(map<int, int>& M, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;

    int val = postorder.at(postEnd);
    TreeNode *root = new TreeNode(val);
    int i = M.at(val);

    root->left = buildTreeRe(M, postorder, inStart, i-1, postStart, postEnd-1-(inEnd-i));
    root->right = buildTreeRe(M, postorder, i+1, inEnd, postEnd-(inEnd-i), postEnd-1);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        if (n == 0) return nullptr;

        map<int, int> M;
        for (int i = 0; i < n; i++) M[inorder.at(i)] = i;

        return buildTreeRe(M, postorder, 0, n-1, 0, n-1);
    }
};

int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Solution
    Solution sol;
    auto ans = sol.buildTree(inorder, postorder);

    if (ans == nullptr) cout << "NULL" << endl;

    return 0;
}