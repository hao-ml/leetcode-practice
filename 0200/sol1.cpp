
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid.at(0).size();
        queue<pair<int, int>> q;
        set<pair<int, int>> s;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pair<int, int> p(i, j);
                if (s.find(p) != s.end()) continue;
                s.insert(p);
                if (grid.at(i).at(j) == '0') continue;
                q.push(p);
                ans++;
                while (!q.empty()) {
                    int sz = q.size();
                    for (int k = 0; k < sz; k++) {
                        int ki = q.front().first;
                        int kj = q.front().second;
                        if (ki-1 >= 0) checkElement(ki-1, kj, q, s, grid);
                        if (ki+1 < m) checkElement(ki+1, kj, q, s, grid);
                        if (kj-1 >= 0) checkElement(ki, kj-1, q, s, grid);
                        if (kj+1 < n) checkElement(ki, kj+1, q, s, grid);
                        q.pop();                        
                    }
                }
            }
        }

        return ans;
    }
private:
    void checkElement(int i, int j, queue<pair<int, int>> &q, set<pair<int, int>> &s, vector<vector<char>> &grid) {
        pair<int, int> p(i, j);
        if (s.find(p) == s.end()) {
            s.insert(p);
            if (grid.at(i).at(j) == '1') q.push(p);
        }
    }
};

int main() {
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'},};
    Solution sol;
    cout << sol.numIslands(grid) << endl;

    return 0;
}