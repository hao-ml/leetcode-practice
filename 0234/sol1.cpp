#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode *ptr = head;
        int listLength = 1;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            listLength++;
        }
        ListNode *tail = ptr;
        
        ptr = head;
        for(int i = 0; i < listLength / 2; i++) {
            ptr = ptr->next;
        }

        if (ptr->next != NULL) {
            ListNode *pre = ptr;
            ptr = ptr->next;
            pre->next = NULL; // Otherwise AddressSanitizer error
            ListNode *nxt = ptr->next;
            ptr->next = pre;
            while(nxt != NULL) {
                pre = ptr;
                ptr = nxt;
                nxt = ptr->next;
                ptr->next = pre;
            }
        }

        for (int i = 0; i < listLength / 2; i++) {
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};

int main() {

    ListNode *ptr1 = new ListNode(1);
    ListNode *ptr2 = new ListNode(2);
    ptr1->next = ptr2;
    
    printLinkedList(ptr1);
    
    Solution sol;
    cout << sol.isPalindrome(ptr1) << endl;
    
    
    ListNode *ptr3 = new ListNode(2);
    ListNode *ptr4 = new ListNode(1);
    
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    
    printLinkedList(ptr1);

    cout << sol.isPalindrome(ptr1) << endl;

    ListNode *head = new ListNode(1);
    ListNode *ptr5 = new ListNode(2);
    ListNode *ptr6 = new ListNode(3);
    ListNode *ptr7 = new ListNode(2);
    ListNode *ptr8 = new ListNode(1);
    head->next = ptr5;
    ptr5->next = ptr6;
    ptr6->next = ptr7;
    ptr7->next = ptr8;
    printLinkedList(head);
    cout << sol.isPalindrome(head) << endl;

 
    return 0;
  
}