
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string init = "0000";
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        if (deadset.count(init)) return -1;
        if (target == init) return 0;
        int turn = 0;
        queue<string> q;
        unordered_set<string> visited;

        q.push(init);
        visited.insert(init);

        while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string s = q.front(); 
                q.pop();
                for (int j = 0; j < s.length(); j++) {
                    vector<char> cc(2);
                    cc.at(0) = (s.at(j) == '0') ? '9' : char(s.at(j) - 1);
                    cc.at(1) = (s.at(j) == '9') ? '0' : char(s.at(j) + 1);
                    for (auto c : cc) {
                        string sNext = s;
                        sNext.at(j) = c;
                        if (sNext == target) return ++turn;
                        if (!visited.count(sNext) && !deadset.count(sNext)) q.push(sNext);
                        visited.insert(sNext);
                    }
                }
            }
            turn++;
        }

        return -1;
    }
};

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    Solution sol;

    cout << sol.openLock(deadends, target) << endl;

    return 0;
}