#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

void printList(ListNode *head) {
    ListNode *cur = head;
    while (cur != nullptr) {
        
        cout << cur->val << " -> ";
        cur = cur->next;
    
    }
    cout << "null" << endl;
}

ListNode *initializeList(int N) {
    int x;
    cin >> x;;
    ListNode *head = new ListNode(x);
    ListNode *pre = head;

    for (int i = 1; i < N; i++) {
        int x;
        cin >> x;
        ListNode *ptr = new ListNode(x);
        pre -> next = ptr;
        pre = ptr;
    }

    return head;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *ptr0 = new ListNode();
        ptr0 -> next = head;
        ListNode *pre = ptr0;
        ListNode *ptrFast = head;
        ListNode *ptrSlow = head;

        int i = 1;
        while (i < n) {
            ptrFast = ptrFast -> next;
            i++;
        }

        while (ptrFast -> next != nullptr) {
            ptrFast = ptrFast -> next;
            ptrSlow = ptrSlow -> next;
            pre = pre -> next;
        }

        pre -> next = ptrSlow -> next;

        return ptr0 -> next;        
    }
};

int main() {

    int N;
    cin >> N;
    int n;
    cin >> n;

    ListNode *head = initializeList(N);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    printList(head);

    return 0;
  
}
