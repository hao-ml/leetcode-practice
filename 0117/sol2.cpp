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
        Node *guard = new Node(), *curr = guard, *head = root;
        
        while (root) {
            if (root->left) {
                curr->next = root->left;
                curr = curr->next;
            }
            if (root->right) {
                curr->next = root->right;
                curr = curr->next;
            }
            root = root->next;
            if (!root) {
                curr = guard;
                root = guard->next;
                guard->next = nullptr;
            }
        }
        
        return head;
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