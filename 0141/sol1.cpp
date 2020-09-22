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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;

        ListNode *slowPtr = head;
        ListNode *fastPtr = head->next;

        while(fastPtr != NULL && fastPtr != slowPtr) {
            fastPtr = fastPtr->next;
            if (fastPtr == NULL) return false;
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }

        if (fastPtr == NULL) return false;
        else return true;

    }
};

int main() {

    ListNode *head = new ListNode(0);

    Solution sol;
    cout << sol.hasCycle(head) << endl;

    ListNode *ptr1 = new ListNode(1);
    head->next = ptr1;

    ListNode *ptr2 = new ListNode(2);
    head->next->next = ptr2;
    ptr2->next = head;

    cout << sol.hasCycle(head) << endl;
 
    return 0;
  
}