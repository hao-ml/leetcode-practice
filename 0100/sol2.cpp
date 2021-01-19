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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkp, stkq;
        if (!isValid(p, q)) return false;
        if (!p && !q) return true;
        stkp.push(p); stkq.push(q);
        while(!stkp.empty()) {
            auto p_ = stkp.top(); stkp.pop();
            auto q_ = stkq.top(); stkq.pop();
            if (!isValid(p_->left, q_->left)) return false;
            if (p_->left && q_->left) {stkp.push(p_->left); stkq.push(q_->left);}
            if (!isValid(p_->right, q_->right)) return false;
            if (p_->right && q_->right) {stkp.push(p_->right); stkq.push(q_->right);}
        }
        return true;
    }
private:
    bool isValid(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return true;
    }
};

int main() {

    TreeNode *p = new TreeNode(1);
    TreeNode *ptr1 = new TreeNode(2);
    TreeNode *ptr2 = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    TreeNode *ptr3 = new TreeNode(2);
    TreeNode *ptr4 = new TreeNode(3);
    
    p->left = ptr1;
    p->right = ptr2;
    
    q->left = ptr3;
    q->right = ptr4;    
    
    auto matP = levelOrder(p);
    print2DArray(matP);

    auto matQ = levelOrder(q);
    print2DArray(matQ);

    // Solution
    Solution sol;
    auto ans = sol.isSameTree(p, q);
    cout << "Answer: " << ans << endl;

    return 0;
}