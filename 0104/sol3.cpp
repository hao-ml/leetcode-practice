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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        vector<int> memo;
        helper(root, 0, memo);
        int ans = 0;
        for (auto level : memo) {
            ans = (level > ans) ? level : ans;
        }
        return ans;
    }
private:
    void helper(TreeNode *root, int level, vector<int> &memo) {
        if (root) {
            memo.push_back(++level);
            helper(root->left, level, memo);
            helper(root->right, level, memo);
        }
    }
};

int main() {
    
    TreeNode *root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    Solution s;
    cout << s.maxDepth(root) << endl;

    return 0;
  
}