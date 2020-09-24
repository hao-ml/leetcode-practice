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
        ListNode *head0 = new ListNode();
        ListNode *head1 = new ListNode();
        ListNode *cur0 = head0;
        ListNode *cur1 = head1;
        int i = 0;

        while (head != nullptr) {
            if (i % 2 == 0) {
                cur0->next = head;
                cur0 = cur0->next;
            }
            else {
                cur1->next = head;
                cur1 = cur1->next;
            }
            head = head->next;
            i++;
        }

        cur1->next = nullptr;
        cur0->next = head1->next;

        return head0->next;
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