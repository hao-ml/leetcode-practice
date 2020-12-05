#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int y;
        while (input.size() > 1) {
            y = input.front(); input.pop();
            output.push(y);
        }
        y = input.front(); input.pop();
        while (!output.empty()) {
            int x = output.front(); output.pop();
            input.push(x);
        }

        return y;
    }
    
    /** Get the top element. */
    int top() {
        int y;
        while (!input.empty()) {
            y = input.front(); input.pop();
            output.push(y);
        }
        while (!output.empty()) {
            int x = output.front(); output.pop();
            input.push(x);
        }

        return y;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
private:
    queue<int> input;
    queue<int> output;
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop(); cout << param_2 << endl;
    int param_3 = obj->top(); cout << param_3 << endl;
    bool param_4 = obj->empty(); cout << param_4 << endl;

    return 0;
} 