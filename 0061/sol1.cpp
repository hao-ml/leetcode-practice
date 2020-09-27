#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode *head) {
    while(head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        int len = 1;
        ListNode *tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k %= len;

        for(int i = 0; i < len - k; i++){
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        
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

    int k = 2;

    Solution sol;
    ListNode *head = sol.rotateRight(ptr1, k);
    printLinkedList(head);

    return 0;
  
}