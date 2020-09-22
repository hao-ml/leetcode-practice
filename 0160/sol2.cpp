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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != curB) {
            if (curA != NULL) curA = curA->next;
            else curA = headB;

            if (curB != NULL) curB = curB->next;
            else curB = headA;
        }

        return curA;
    }

};

int main() {

    ListNode *headA = new ListNode(11);
    ListNode *ptrA2 = new ListNode(12);
    headA->next = ptrA2;

    ListNode *headB = new ListNode(21);
    ListNode *ptrB2 = new ListNode(22);
    ListNode *ptrB3 = new ListNode(23);
    headB->next = ptrB2;
    ptrB2->next = ptrB3;

    ListNode *ptrC1 = new ListNode(31);
    ptrA2->next = ptrC1;
    ptrB3->next = ptrC1;
    
    ListNode *ptrC2 = new ListNode(32);
    ListNode *ptrC3 = new ListNode(33);
    ptrC1->next = ptrC2;
    ptrC2->next = ptrC3;

    printLinkedList(headA);
    printLinkedList(headB);

    Solution sol;
    cout << sol.getIntersectionNode(headA, headB)->val << endl;
 
    return 0;
  
}