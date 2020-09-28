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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        
        if (root != nullptr) {
            s.push(root);
            while (!s.empty()) {
                auto thisNode = s.top();
                ans.push_back(thisNode->val);
                s.pop();
                if (thisNode->right != nullptr) 
                    s.push(thisNode->right);
                if (thisNode->left != nullptr) 
                    s.push(thisNode->left);
            }
        }

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
    auto ans = sol.preorderTraversal(root);
    printArray(ans);

    return 0;
}