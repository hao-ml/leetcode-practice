
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0;
        tail = 0;
        n = 0, sz = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        q.at(tail) = value;
        ++tail %= sz;
        n++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        ++head %= sz;
        n--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return q.at(head);
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        int i = tail - 1;
        i = (i < 0) ? (sz + i) : i;
        return q.at(i);
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return n == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return n == sz;
    }
private:
    vector<int> q;
    int head, tail;
    int n, sz;
};

int main() {
    int k = 2;
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(1);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    return 0;
}