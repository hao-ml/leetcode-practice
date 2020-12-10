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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode *newHead = cur->next->next->next;
            head = cur->next;
            cur->next = head->next;
            cur = head;
            head->next->next = head;
            head->next = newHead;
        }
        return dummy->next;
    }
};

int main() {

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLinkedList(n1);

    Solution sol;
    auto ans = sol.swapPairs(n1);
    printLinkedList(ans);

    return 0;
  
}