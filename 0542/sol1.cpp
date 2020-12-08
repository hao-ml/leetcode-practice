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
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int nr = matrix.size(), nc = matrix[0].size();
        bool isFound = false;
        for (int ir = 0; ir < nr; ir++) {
            for (int ic = 0; ic < nc; ic++) {
                queue<pair<int, int>> que; que.push({ir, ic});
                for (int d = 0; ; d++) {
                    int n = que.size();
                    for (int i = 0; i < n; i++) {
                        int r = que.front().first, c = que.front().second;
                        que.pop();
                        if (matrix[r][c] == 0) {
                            matrix[ir][ic] = d; 
                            isFound = true; break;
                        }
                        if (r - 1 >= 0) que.push({r - 1, c});
                        if (r + 1 < nr) que.push({r + 1, c});
                        if (c - 1 >= 0) que.push({r, c - 1});
                        if (c + 1 < nc) que.push({r, c + 1});
                    }
                    if (isFound) {isFound = false; break;}
                }
            }
        }

        return matrix;
    }
};

int main() {
    // vector<vector<int>> matrix = {{0,0,0}, {0,1,0}, {1,1,1}};
    vector<vector<int>> matrix = {{0,0,1,0,1,1,1,0,1,1},
                                  {1,1,1,1,0,1,1,1,1,1},
                                  {1,1,1,1,1,0,0,0,1,1},
                                  {1,0,1,0,1,1,1,0,1,1},
                                  {0,0,1,1,1,0,1,1,1,1},
                                  {1,0,1,1,1,1,1,1,1,1},
                                  {1,1,1,1,0,1,0,1,0,1},
                                  {0,1,0,0,0,1,0,0,1,1},
                                  {1,1,1,0,1,1,0,1,0,1},
                                  {1,0,1,1,1,0,1,1,1,0}};
    cout << "Input:" << endl; printMatrix(matrix);
    Solution sol;
    auto ans = sol.updateMatrix(matrix);
    cout << "Output:" << endl; printMatrix(ans);

    return 0;
} 