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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {

    ListNode *l1 = new ListNode(1);
    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    l1->next = l11;
    l11->next = l12;
    printLinkedList(l1);

    ListNode *l2 = new ListNode(1);
    ListNode *l21 = new ListNode(3);
    ListNode *l22 = new ListNode(4);
    l2->next = l21;
    l21->next = l22;
    printLinkedList(l2);

    Solution sol;
    printLinkedList(sol.mergeTwoLists(l1, l2));

    return 0;
  
}