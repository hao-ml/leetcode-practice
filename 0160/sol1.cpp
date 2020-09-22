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
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        if (lenA == 0 || lenB == 0) return NULL;
        
        ListNode *curA = headA;
        ListNode *curB = headB;
        if (lenA > lenB) {
            int dLen = lenA - lenB;
            while (dLen > 0) {
                curA = curA->next;
                dLen--;
            }
        }
        else {
            int dLen = lenB - lenA;
            while (dLen > 0) {
                curB = curB->next;
                dLen--;
            }
        }

        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }

        return curA;
    }

    int getListLength(ListNode *head) {
        int length = 0;
        while (head != NULL) {
            head = head->next;
            length++;
        }
        return length;
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