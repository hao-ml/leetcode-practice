
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
                if (visited.at(i).at(j) || grid.at(i).at(j) == '0') continue;
                ans++;
                numIslandsFunc(i, j, grid, visited);
            }
        }

        return ans;
    }
private:
    void numIslandsFunc(int i, int j, vector<vector<char>> &grid, vector<vector <bool>> &visited) {
        int m = grid.size(), n = grid.at(0).size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited.at(i).at(j)) return;
        visited.at(i).at(j) = true;
        if (grid.at(i).at(j) == '0') return;
        numIslandsFunc(i-1, j, grid, visited);
        numIslandsFunc(i+1, j, grid, visited);
        numIslandsFunc(i, j-1, grid, visited);
        numIslandsFunc(i, j+1, grid, visited);
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