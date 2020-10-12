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

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.size() == 0) return nullptr;

        int val = postorder.back();
        TreeNode *root = new TreeNode(val);

        if (inorder.size() == 1) return root;

        auto it = find(inorder.begin(), inorder.end(), val);
        int nL = distance(inorder.begin(), it);
        int nR = distance(it, inorder.end()) - 1;

        if (nL == 0) root->left = nullptr;
        else {
            vector<int> inL(inorder.begin(), it);
            vector<int> postL(postorder.begin(), postorder.begin() + nL);
            root->left = buildTree(inL, postL);
        }

        if (nR == 0) root->right = nullptr;
        else {
            vector<int> inR(it + 1, inorder.end());        
            vector<int> postR(postorder.begin() + nL, postorder.begin() + nL + nR);
            root->right = buildTree(inR, postR);
        }

        return root;
    }
};

int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Solution
    Solution sol;
    auto ans = sol.buildTree(inorder, postorder);

    return 0;
}