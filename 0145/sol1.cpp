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

void printArray(vector<int> arr) {
    if (arr.size() == 0) cout << "NULL";
    else {
        for (auto a : arr) cout << a << ' ';
    }
    cout << endl;
}

void postorder(TreeNode *root, vector<int> &ans) {
    if (root != nullptr) {
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

int main() {

    // Example 1
    cout << "Example 1:" << endl;
    TreeNode *root = new TreeNode(1);
    TreeNode *ptr1 = new TreeNode(2);
    TreeNode *ptr2 = new TreeNode(3);
    root->right = ptr1;
    ptr1->left = ptr2;

    // Example 4
    // cout << "Example 4:" << endl;
    // TreeNode *root = new TreeNode(1);
    // TreeNode *ptr1 = new TreeNode(2);
    // root->left = ptr1;

    // Example 5
    // cout << "Example 5:" << endl;
    // TreeNode *root = new TreeNode(1);
    // TreeNode *ptr1 = new TreeNode(2);
    // root->right = ptr1;

    // Solution
    Solution sol;
    auto ans = sol.postorderTraversal(root);
    printArray(ans);

    return 0;
}