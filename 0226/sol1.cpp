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

void invert(TreeNode *root) {
    if (root != nullptr) {
        auto thisPtr = root->left;
        root->left = root->right;
        root->right = thisPtr;

        invert(root->left);
        invert(root->right);
    }
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

int main() {

    TreeNode *root = new TreeNode(4);
    TreeNode *ptr1 = new TreeNode(2);
    TreeNode *ptr2 = new TreeNode(7);
    TreeNode *ptr3 = new TreeNode(1);
    TreeNode *ptr4 = new TreeNode(3);
    TreeNode *ptr5 = new TreeNode(6);
    TreeNode *ptr6 = new TreeNode(9);

    root->left = ptr1;
    root->right = ptr2;
    ptr1->left = ptr3;
    ptr1->right = ptr4;    
    ptr2->left = ptr5;
    ptr2->right = ptr6;

    auto mat = levelOrder(root);
    print2DArray(mat);

    // Solution
    Solution sol;
    auto ans = levelOrder(sol.invertTree(root));
    print2DArray(ans);

    return 0;
}