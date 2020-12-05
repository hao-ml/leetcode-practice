#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!stkRev.empty()) {
            int y = stkRev.top(); stkRev.pop();
            stk.push(y);
        }
        stk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek(); stkRev.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while (!stk.empty()) {
            int y = stk.top(); stk.pop();
            stkRev.push(y);
        }
        int x = stkRev.top();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (stk.empty() && stkRev.empty());
    }
private:
    stack<int> stk;
    stack<int> stkRev;
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop(); cout << param_2 << endl;
    int param_3 = obj->peek(); cout << param_3 << endl;
    bool param_4 = obj->empty(); cout << param_4 << endl;

    return 0;
} 