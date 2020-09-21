#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
    SinglyListNode *head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        SinglyListNode *cur = head;
        for (int i = 0; i < index; i++) {
            if (cur == NULL) return -1;
            cur = cur->next;
        }
        if (cur == NULL) return -1;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. 
     * After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode *ptr = new SinglyListNode(val);
        ptr->next = head;
        head = ptr;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode *ptr = new SinglyListNode(val);
        if (head == NULL) {
            head = ptr;
            return;
        }
        SinglyListNode *cur = head;
        while(cur->next != NULL) cur = cur->next;
        cur->next = ptr;
    }
    
    /** Add a node of value val before the index-th node in the linked list. 
     * If index equals to the length of linked list, the node will be appended to the end of linked list. 
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        SinglyListNode *pre = head;
        SinglyListNode *cur = head->next;
        for (int i = 1; i < index; i++) {
            if (cur == NULL) return;
            pre = cur;
            cur = cur->next;
        }
        SinglyListNode *ptr = new SinglyListNode(val);
        pre->next = ptr;
        ptr->next = cur;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            head = head->next;
            return;
        }
        SinglyListNode *pre = head;
        SinglyListNode *cur = head->next;
        for (int i = 1; i < index; i++) {
            if (cur == NULL) return;
            pre = cur;
            cur = cur->next;
        }
        if (cur == NULL) return;
        pre->next = cur->next;
    }
};

void printLinkedList(SinglyListNode *head) {
    while(head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    //  Your MyLinkedList object will be instantiated and called as such:
    // MyLinkedList* obj = new MyLinkedList();
    // int param_1 = obj->get(index);
    // obj->addAtHead(val);
    // obj->addAtTail(val);
    // obj->addAtIndex(index,val);
    // obj->deleteAtIndex(index);

    MyLinkedList *obj = new MyLinkedList();
    printLinkedList(obj->head);

    obj->addAtHead(1);
    printLinkedList(obj->head);
    
    obj->addAtTail(3);
    printLinkedList(obj->head);
    
    obj->addAtIndex(1, 2);
    printLinkedList(obj->head);
    
    cout << obj->get(1) << endl;

    obj->deleteAtIndex(1);
    printLinkedList(obj->head);

    cout << obj->get(1) << endl;
 
    return 0;
  
}