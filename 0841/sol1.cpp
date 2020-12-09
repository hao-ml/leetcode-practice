#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> mat) {
    if (mat.size() == 0) cout << "NULL" << endl;
    else {
        for (auto arr : mat) {
            if (arr.size() == 0) cout << "NULL";
            else for (auto a : arr) cout << a << ' ';
            cout << endl;
        }
    }
}

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) return false;
        int n = rooms.size();
        stack<int> stk;
        unordered_set<int> visited;
        stk.push(0); visited.insert(0);
        while (!stk.empty()) {
            int room = stk.top(); stk.pop();
            auto keys = rooms[room];
            for (int k = 0; k < keys.size(); k++) {
                if (visited.count(keys[k])) continue;
                stk.push(keys[k]); 
                visited.insert(keys[k]);
                if (visited.size() == n) return true;
            }
        }
        return (visited.size() == n);
    }
};

int main() {
    // vector<vector<int>> rooms = {{1},{2},{3},{}};
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    
    cout << "Rooms:" << endl; printMatrix(rooms);
    Solution sol;
    cout << "Answer: " << sol.canVisitAllRooms(rooms) << endl;

    return 0;
} 