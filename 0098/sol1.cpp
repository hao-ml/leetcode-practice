#include <bits/stdc++.h>
using namespace std;

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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
private:
    bool helper(TreeNode* root, long lower, long upper) {
        if (!root) return true;
        if (root->val >= upper || root->val <= lower) return false;
        return helper(root->left,  lower, root->val) && 
               helper(root->right, root->val, upper);
    }
};

int main() {

    return 0;
}