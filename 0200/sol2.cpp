
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.at(0).empty()) return 0;

        int ans = 0;
        int m = grid.size(), n = grid.at(0).size();
        vector<vector <bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited.at(i).at(j)) continue;
                visited.at(i).at(j) = true;
                if (grid.at(i).at(j) == '0') continue;
                ans++;
                pair<int, int> p(i, j);
                queue<pair<int, int>> q{{p}};
                while (!q.empty()) {
                    int ii = q.front().first;
                    int jj = q.front().second;
                    if (ii-1 >= 0) checkElement(ii-1, jj, q, visited, grid);      
                    if (ii+1 <  m) checkElement(ii+1, jj, q, visited, grid);
                    if (jj-1 >= 0) checkElement(ii, jj-1, q, visited, grid);
                    if (jj+1 <  n) checkElement(ii, jj+1, q, visited, grid);
                    q.pop();      
                }
            }
        }

        return ans;
    }
private:
    void checkElement(int i, int j, queue<pair<int, int>> &q, vector<vector <bool>> &visited, vector<vector<char>> &grid) {
        if (visited.at(i).at(j)) return;
        pair<int, int> p(i, j);
        visited.at(i).at(j) = true;
        if (grid.at(i).at(j) == '1') q.push(p);
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