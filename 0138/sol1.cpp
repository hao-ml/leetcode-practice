#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

void printLinkedList(Node *head) {
    while(head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

void printRandomNode(Node *head) {
    while(head != nullptr) {
        if (head->random == nullptr) cout << "nullptr" << ' ';
        else cout << head->random->val << ' ';
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr0 = new Node(0);
        Node *curr = head;
        Node *prevNew = ptr0;
        map<Node*, Node*> addressMap;

        while (curr != nullptr) {
            Node *thisNode = new Node(curr->val);
            prevNew->next = thisNode;
            addressMap.insert({curr, thisNode});
            prevNew = prevNew->next;
            curr = curr->next;
        }

        Node *currNew = ptr0->next;
        curr = head;
        while (currNew != nullptr) {
            currNew->random = addressMap[curr->random];
            currNew = currNew->next;
            curr = curr->next;
        }

        return ptr0->next;    
    }
};

int main() {

    Node *ptr1 = new Node(7);
    Node *ptr2 = new Node(13);
    Node *ptr3 = new Node(11);
    Node *ptr4 = new Node(10);
    Node *ptr5 = new Node(1);

    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = ptr5;

    ptr1->random = nullptr;
    ptr2->random = ptr1;
    ptr3->random = ptr5;
    ptr4->random = ptr3;
    ptr5->random = ptr1;

    printLinkedList(ptr1);
    printRandomNode(ptr1);

    Solution sol;
    Node *head = sol.copyRandomList(ptr1);
    printLinkedList(head);
    printRandomNode(head);

    return 0;
  
}