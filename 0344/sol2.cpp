#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        if (s.empty()) return;
        helper(s, 0, s.size()-1);

    }
private:
    void helper(vector<char> &s, int left, int right) {
        if (left >= right) return;
        swap(s[left], s[right]);
        helper(s, left+1, right-1);
    }
};

int main() {
    
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;
    sol.reverseString(s);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s.at(i) << ' ';
    }
    cout << endl;

    return 0;
  
}
