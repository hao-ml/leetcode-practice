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

bool symmetric(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    else if (root1 != nullptr && root2 != nullptr)
        return (root1->val == root2->val) && 
               symmetric(root1->left, root2->right) &&
               symmetric(root1->right, root2->left);
    else return false;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        
        if (root != nullptr) 
            ans = symmetric(root->left, root->right);
        
        return ans;
    }
};

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *ptr1 = new TreeNode(2);
    TreeNode *ptr2 = new TreeNode(2);
    TreeNode *ptr3 = new TreeNode(3);
    TreeNode *ptr4 = new TreeNode(4);
    TreeNode *ptr5 = new TreeNode(4);
    TreeNode *ptr6 = new TreeNode(3);

    root->left = ptr1;
    root->right = ptr2;
    ptr1->left = ptr3;
    ptr1->right = ptr4;    
    ptr2->left = ptr5;
    ptr2->right = ptr6;

    // Solution
    Solution sol;
    auto ans = sol.isSymmetric(root);
    cout << ans << endl;

    return 0;
}