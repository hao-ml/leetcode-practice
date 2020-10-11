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
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) ans = true;
            else if (root->left != nullptr && root->right != nullptr) {
                stack<TreeNode*> sL;
                stack<TreeNode*> sR;
                sL.push(root->left);
                sR.push(root->right);

                while(!sL.empty() && !sR.empty()) {
                    auto thisL = sL.top();
                    auto thisR = sR.top();
                    if (thisL->val != thisR->val) return false;
                    sL.pop();
                    sR.pop();
                    if (thisL->right != nullptr && thisR->left != nullptr) {
                        sL.push(thisL->right);
                        sR.push(thisR->left);
                    }
                    else if (thisL->right != nullptr || thisR->left != nullptr) return false; 
                    if (thisL->left != nullptr && thisR->right != nullptr) {
                        sL.push(thisL->left);
                        sR.push(thisR->right);
                    }
                    else if (thisL->left != nullptr || thisR->right != nullptr) return false; 
                }
                ans = true;
            }
            else ans = false;
        } 
                    
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