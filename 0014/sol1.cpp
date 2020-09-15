#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs.at(0);
        
        string ans = "";
        string str = strs.at(0);
        bool isDone = false;
        for (int i = 0; i < str.size(); i++) {
            char c = str.at(i);
            for (int j = 1; j < strs.size(); j++) {
                string thisStr = strs.at(j);
                if (thisStr.size() < i + 1 || thisStr.at(i) != c) {
                    isDone = true;
                    break;
                }
            }
            if (isDone) break;
            ans.push_back(c);
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
