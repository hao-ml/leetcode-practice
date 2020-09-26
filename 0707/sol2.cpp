#include <bits/stdc++.h>
using namespace std;

// Definition for doubly-linked list.
struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class MyLinkedList {
public:
    DoublyListNode *head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        DoublyListNode *cur = head;
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
        DoublyListNode *ptr = new DoublyListNode(val);
        if (head != NULL) head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        DoublyListNode *ptr = new DoublyListNode(val);
        if (head == NULL) {
            head = ptr;
            return;
        }
        DoublyListNode *cur = head;
        while(cur->next != NULL) cur = cur->next;
        ptr->prev = cur;
        ptr->next = NULL;
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
        DoublyListNode *pre = head;
        DoublyListNode *cur = head->next;
        for (int i = 1; i < index; i++) {
            if (cur == NULL) return;
            pre = cur;
            cur = cur->next;
        }
        DoublyListNode *ptr = new DoublyListNode(val);
        ptr->prev = pre;
        ptr->next = cur;
        pre->next = ptr;
        if (cur != NULL) cur->prev = ptr;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            head = head->next;
            if (head != NULL) head->prev = NULL;
            return;
        }
        DoublyListNode *pre = head;
        DoublyListNode *cur = head->next;
        for (int i = 1; i < index; i++) {
            if (cur == NULL) return;
            pre = cur;
            cur = cur->next;
        }
        if (cur == NULL) return;
        pre->next = cur->next;
        if (cur->next != NULL) cur->next->prev = pre;
    }
};

void printLinkedList(DoublyListNode *head) {
    while(head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    MyLinkedList *obj = new MyLinkedList();
    printLinkedList(obj->head);

    // obj->addAtHead(1);
    // printLinkedList(obj->head);
    
    // obj->addAtTail(3);
    // printLinkedList(obj->head);
    
    // obj->addAtIndex(1, 2);
    // printLinkedList(obj->head);
    
    // cout << obj->get(1) << endl;

    // obj->deleteAtIndex(1);
    // printLinkedList(obj->head);

    // cout << obj->get(1) << endl;

    obj->addAtHead(1);
    printLinkedList(obj->head);

    obj->deleteAtIndex(0);
    printLinkedList(obj->head);
 
    return 0;
  
}