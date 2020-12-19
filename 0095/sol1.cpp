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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode*> ans;
        for (int i = l; i <= r; i++) {
            auto ansL = helper(l, i - 1);
            auto ansR = helper(i + 1, r);
            for (auto nodeL : ansL) {
                for (auto nodeR : ansR) {
                    TreeNode *node = new TreeNode(i);
                    node->left = nodeL;
                    node->right = nodeR;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};

int main() {
    int n = 3;
    Solution sol;
    sol.generateTrees(3);

    return 0;
}
