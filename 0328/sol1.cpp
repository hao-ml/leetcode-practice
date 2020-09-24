#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode *head) {
    while(head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *head0 = head;
        ListNode *head1 = head->next;
        ListNode *cur0 = head0;
        ListNode *cur1 = head1;
        ListNode *pre0 = NULL;
        ListNode *pre1 = NULL;

        while (cur0 != NULL && cur0->next != NULL) {
            cur0->next = cur0->next->next;
            pre0 = cur0;
            cur0 = cur0->next;
            if (cur1 != NULL && cur1->next != NULL) {
                cur1->next = cur1->next->next;
                pre1 = cur1;
                cur1 = cur1->next;
            }
        }

        if (cur0 == NULL) pre0->next = head1;
        else cur0->next = head1;

        return head0;
    }
};

int main() {

    ListNode *ptr1 = new ListNode(1);
    ListNode *ptr2 = new ListNode(2);
    ListNode *ptr3 = new ListNode(3);
    ListNode *ptr4 = new ListNode(4);
    ListNode *ptr5 = new ListNode(5);

    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = ptr5;

    printLinkedList(ptr1);

    Solution sol;
    ListNode *head = sol.oddEvenList(ptr1);
    
    printLinkedList(head);
 
    return 0;
  
}