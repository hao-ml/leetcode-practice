
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        sz = 0;
    }
    
    void push(int x) {
        data.push_back(x);
        if (!sz) {
            minimum.push_back(x);
            sz++;
        }
        else {
            if (x < minimum.at(sz-1)) minimum.push_back(x);
            else minimum.push_back(minimum.at(sz-1));
            sz++;
        }
    }
    
    void pop() {
        if (!sz) return;
        data.pop_back();
        minimum.pop_back();
        sz--;
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minimum.back();
    }
private:
    int sz;
    vector<int> data;
    vector<int> minimum;
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;

    return 0;
}