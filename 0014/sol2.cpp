#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        if (strs.empty()) {
            return "";
        }
        string ans = strs.at(0);

        for (string s : strs) {
            while (s.find(ans) != 0) {
                if (ans.empty()) {
                    return "";
                }
                ans.pop_back();
            }
        }
        
        return ans;
    }
};

void printStrs(vector<string> &strs) {
    for (int i = 0; i < strs.size(); i++) {
        cout << strs.at(i) << endl;
    }
}

int main() {
    
    int N;
    cin >> N;
    cin.ignore();

    vector<string> strs(N);
    for (int i = 0; i < N; i++) {
        getline(cin, strs.at(i));
    }

    printStrs(strs);

    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
  
}
