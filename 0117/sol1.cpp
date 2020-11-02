#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        Node *nxt = root->next;
        while (nxt) {
            if (nxt->left) {
                nxt = nxt->left;
                break;
            }
            if (nxt->right) {
                nxt = nxt->right;
                break;
            }
            nxt = nxt->next;
        }
        if (root->right) root->right->next = nxt;
        if (root->left) root->left->next = root->right ? root->right : nxt;
        connect(root->right);
        connect(root->left);

        return root;
    }
};

int main() {

    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> preorder = {3, 9, 20, 15, 7};

    // // Solution
    // Solution sol;
    // auto ans = sol.buildTree(inorder, preorder);

    // if (ans == nullptr) cout << "NULL" << endl;

    return 0;
}