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
        if(root == nullptr) {
            return 0;
        }
        
        stack<TreeNode*> s;
        stack<int> d;
        int maxD = 1;

        s.push(root);
        d.push(1);
        
        while(!s.empty()) {
            TreeNode *ptr = s.top();
            s.pop();
            cout << ptr -> val << ' ';
            int thisD = d.top();
            d.pop();
            cout << thisD << endl;
            if (maxD < thisD) {
                maxD = thisD;
            }
            if (ptr -> right != nullptr) {
                s.push(ptr -> right);
                d.push(thisD + 1);
            }
            
            if (ptr -> left != nullptr) {
                s.push(ptr -> left);
                d.push(thisD + 1);
            }
        }

        return maxD;
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
