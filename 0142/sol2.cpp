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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode *slowPtr = head;
        ListNode *fastPtr = head->next;

        while(fastPtr != NULL && fastPtr != slowPtr) {
            fastPtr = fastPtr->next;
            if (fastPtr == NULL) return NULL;
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }

        if (fastPtr == NULL) return NULL;
        else {
            slowPtr = slowPtr->next;
            fastPtr = head;
            while (slowPtr != fastPtr) {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            return slowPtr;
        };

    }
};

int main() {

    ListNode *head = new ListNode(0);

    Solution sol;
    cout << sol.detectCycle(head) << endl;

    ListNode *ptr1 = new ListNode(1);
    head->next = ptr1;

    ListNode *ptr2 = new ListNode(2);
    head->next->next = ptr2;
    ptr2->next = head;

    cout << sol.detectCycle(head)->val << endl;
 
    return 0;
  
}