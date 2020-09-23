#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *pre = head;
        head = head->next;
        pre->next = NULL;
        ListNode *nxt = head->next;
        head->next = pre;

        while(nxt != NULL) {
            pre = head;
            head = nxt;
            nxt = nxt->next;
            head->next = pre;
        }

        return head;
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
    ListNode *head = sol.reverseList(ptr1);
    printLinkedList(head);
 
    return 0;
  
}