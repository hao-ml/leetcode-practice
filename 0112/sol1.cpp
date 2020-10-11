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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root != nullptr) 
            if (root->left == nullptr && root->right == nullptr) {
                if (root->val == sum) return true;
                else return false;
            }
            else {
                return hasPathSum(root->left, sum - root->val) ||
                    hasPathSum(root->right, sum - root->val);
            }
        else return false;
    }
};

int main() {

    TreeNode *root = new TreeNode(5);
    TreeNode *ptr1 = new TreeNode(4);
    TreeNode *ptr2 = new TreeNode(8);
    root->left = ptr1;
    root->right = ptr2;

    TreeNode *ptr3 = new TreeNode(11);
    ptr1->left = ptr3;

    TreeNode *ptr4 = new TreeNode(13);
    TreeNode *ptr5 = new TreeNode(4);
    ptr2->left = ptr4;
    ptr2->right = ptr5;

    TreeNode *ptr6 = new TreeNode(7);
    TreeNode *ptr7 = new TreeNode(2);
    ptr3->left = ptr6;
    ptr3->right = ptr7;

    TreeNode *ptr8 = new TreeNode(1);
    ptr5->right = ptr8;

    int sum = 22;

    // Solution
    Solution sol;
    auto ans = sol.hasPathSum(root, sum);
    cout << ans << endl;

    return 0;
}