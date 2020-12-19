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
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    }
private:
    vector<TreeNode*> helper(int l, int r, vector<vector<vector<TreeNode*>>> &memo) {
        if (l > r) return {nullptr};
        if (!memo[l - 1][r - 1].empty()) return memo[l - 1][r - 1];
        vector<TreeNode*> ans;
        for (int i = l; i <= r; i++) {
            auto ansL = helper(l, i - 1, memo);
            auto ansR = helper(i + 1, r, memo);
            for (auto nodeL : ansL) {
                for (auto nodeR : ansR) {
                    TreeNode *node = new TreeNode(i);
                    node->left = nodeL;
                    node->right = nodeR;
                    ans.push_back(node);
                }
            }
        }
        memo[l - 1][r - 1] = ans;
        return ans;
    }
};

int main() {
    int n = 3;
    Solution sol;
    sol.generateTrees(n);

    return 0;
}
