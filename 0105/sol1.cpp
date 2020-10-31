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

TreeNode *buildTreeRe(map<int, int>& M, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd || preStart > preEnd) return nullptr;

    int val = preorder.at(preStart);
    TreeNode *root = new TreeNode(val);
    int i = M.at(val);
    int lenL = i - inStart;
    int lenR = inEnd - i;

    root->left = buildTreeRe(M, preorder, inStart, i-1, preStart+1, preStart+lenL);
    root->right = buildTreeRe(M, preorder, i+1, inEnd, preEnd-lenR+1, preEnd);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();
        if (n == 0) return nullptr;

        map<int, int> M;
        for (int i = 0; i < n; i++) M[inorder.at(i)] = i;

        return buildTreeRe(M, preorder, 0, n-1, 0, n-1);
    }
};

int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    // Solution
    Solution sol;
    auto ans = sol.buildTree(inorder, preorder);

    if (ans == nullptr) cout << "NULL" << endl;

    return 0;
}