#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char c = s.at(i);
            s.at(i) = s.at(j);
            s.at(j) = c;
            i++;
            j--;
        }

    }
};

int main() {
    
    int n;
    cin >> n;

    vector<char> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s.at(i);
    }

    Solution sol;
    sol.reverseString(s);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s.at(i) << ' ';
    }
    cout << endl;

    return 0;
  
}
