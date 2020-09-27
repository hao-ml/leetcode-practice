#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

void printLinkedList(Node *head) {
    while(head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node *headChild = flatten(curr->child);
                Node *headNext = flatten(curr->next);
                curr->next = headChild;
                curr->child = nullptr;
                headChild->prev = curr;
                while (headChild->next != nullptr)
                    headChild = headChild->next;
                headChild->next = headNext;
                if (headNext != nullptr) headNext->prev = headChild;
                return head;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {

    // Level 1
    Node *ptr1 = new Node();
    ptr1->val = 1;
    Node *ptr2 = new Node();
    ptr2->val = 2;
    Node *ptr3 = new Node();
    ptr3->val = 3;
    Node *ptr4 = new Node();
    ptr4->val = 4;
    Node *ptr5 = new Node();
    ptr5->val = 5;
    Node *ptr6 = new Node();
    ptr6->val = 6;

    // Level 2
    Node *ptr7 = new Node();
    ptr7->val = 7;
    Node *ptr8 = new Node();
    ptr8->val = 8;
    Node *ptr9 = new Node();
    ptr9->val = 9;
    Node *ptr10 = new Node();
    ptr10->val = 10;

    // Level 3
    Node *ptr11 = new Node();
    ptr11->val = 11;
    Node *ptr12 = new Node();
    ptr12->val = 12;
    
    // Level 1
    ptr1->next = ptr2;
    ptr2->prev = ptr1;

    ptr2->next = ptr3;
    ptr3->prev = ptr2;

    ptr3->next = ptr4;
    ptr4->prev = ptr3;
    
    ptr4->next = ptr5;
    ptr5->prev = ptr4;
    
    ptr5->next = ptr6;
    ptr6->prev = ptr5;

    // Level 2
    ptr7->next = ptr8;
    ptr8->prev = ptr7;

    ptr8->next = ptr9;
    ptr9->prev = ptr8;

    ptr9->next = ptr10;
    ptr10->prev = ptr9;

    // Level 3
    ptr11->next = ptr12;
    ptr12->prev = ptr11;    

    // Children links
    ptr3->child = ptr7;
    ptr8->child = ptr11;

    printLinkedList(ptr1);
    printLinkedList(ptr7);
    printLinkedList(ptr11);

    Solution sol;
    printLinkedList(sol.flatten(ptr1));

    return 0;
  
}