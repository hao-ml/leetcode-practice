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

ListNode* makeSumNode(int sum, int &plusOne) {
    if (sum > 9) {
        sum -= 10;
        plusOne = 1;
    }
    else plusOne = 0;
    ListNode *thisNode = new ListNode(sum);
    return thisNode;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l0 = new ListNode();
        ListNode *cur = l0;

        int plusOne = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + plusOne;
            cur->next = makeSumNode(sum, plusOne);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr) {
            while (l2 != nullptr) {
                int sum = l2->val + plusOne;
                cur->next = makeSumNode(sum, plusOne);
                cur = cur->next;
                l2 = l2->next;
            }
        }
        else {
            while (l1 != nullptr) {
                int sum = l1->val + plusOne;
                cur->next = makeSumNode(sum, plusOne);
                cur = cur->next;
                l1 = l1->next;
            }
        }

        if (plusOne == 1) {
            ListNode *thisNode = new ListNode(1);
            cur->next = thisNode;
        }

        return l0->next;
    }
};

int main() {

    ListNode *l1 = new ListNode(2);
    ListNode *l11 = new ListNode(4);
    ListNode *l12 = new ListNode(3);
    l1->next = l11;
    l11->next = l12;
    printLinkedList(l1);

    ListNode *l2 = new ListNode(5);
    ListNode *l21 = new ListNode(6);
    ListNode *l22 = new ListNode(4);
    l2->next = l21;
    l21->next = l22;
    printLinkedList(l2);

    Solution sol;
    printLinkedList(sol.addTwoNumbers(l1, l2));

    return 0;
  
}