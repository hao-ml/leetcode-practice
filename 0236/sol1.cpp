#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root;
        return l ? l : r;
    }
};

int main() {

    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> preorder = {3, 9, 20, 15, 7};

    // // Solution
    // Solution sol;
    // auto ans = sol.buildTree(inorder, preorder);

    // if (ans == nullptr) cout << "NULL" << endl;

    return 0;
}