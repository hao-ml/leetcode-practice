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

        root->next = nullptr;
        Node *parent = root;
        Node *cur = parent->left;

        while (cur != nullptr) {
            cur->next = parent->right;
            while (parent->next != nullptr) {
                parent->right->next = parent->next->left;
                parent = parent->next;
                parent->left->next = parent->right;
            }
            parent = cur;
            cur = cur->left;
        }

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