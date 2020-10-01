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

void print2DArray(vector<vector<int>> mat) {
    if (mat.size() == 0) cout << "NULL" << endl;
    else {
        for (auto arr : mat) {
            if (arr.size() == 0) cout << "NULL";
            else for (auto a : arr) cout << a << ' ';
            cout << endl;
        }
    }
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        queue<int> qLvl;

        if (root != nullptr) {
            int curLvl = 0;
            vector<int> ansLvl;
            ans.push_back(ansLvl);
            q.push(root);
            qLvl.push(curLvl);

            while (!q.empty()) {
                auto ptr = q.front();
                int lvl = qLvl.front();

                if (lvl > curLvl) {
                    vector<int> ansLvl;
                    ans.push_back(ansLvl);
                    curLvl = lvl;
                }
                ans[curLvl].push_back(ptr->val);
                if (ptr->left != nullptr) {
                    q.push(ptr->left);
                    qLvl.push(lvl + 1);
                }
                if (ptr->right != nullptr) {
                    q.push(ptr->right);
                    qLvl.push(lvl + 1);
                }
                q.pop();
                qLvl.pop();
            }
        }
        
        return ans;
    }
};

int main() {

    TreeNode *root = new TreeNode(3);
    TreeNode *ptr1 = new TreeNode(9);
    TreeNode *ptr2 = new TreeNode(20);
    TreeNode *ptr3 = new TreeNode(15);
    TreeNode *ptr4 = new TreeNode(7);

    root->left = ptr1;
    root->right = ptr2;
    ptr2->left = ptr3;
    ptr2->right = ptr4;

    // Solution
    Solution sol;
    auto ans = sol.levelOrder(root);
    print2DArray(ans);

    return 0;
}