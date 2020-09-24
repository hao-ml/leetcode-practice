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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ptr0 = new ListNode(0);
        ptr0->next = head;
        ListNode *pre = ptr0;
        
        while(head != NULL) {
            if (head->val == val) pre->next = head->next;
            else pre = head;
            head = head->next;
        }

        return ptr0->next;
    }
};

int main() {

    ListNode *ptr1 = new ListNode(1);
    ListNode *ptr2 = new ListNode(2);
    ListNode *ptr3 = new ListNode(6);
    ListNode *ptr4 = new ListNode(3);
    ListNode *ptr5 = new ListNode(4);
    ListNode *ptr6 = new ListNode(5);
    ListNode *ptr7 = new ListNode(6);

    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = ptr5;
    ptr5->next = ptr6;
    ptr6->next = ptr7;

    printLinkedList(ptr1);

    int val = 6;

    Solution sol;
    ListNode *head = sol.removeElements(ptr1, val);
    printLinkedList(head);
 
    return 0;
  
}