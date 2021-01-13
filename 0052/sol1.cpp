#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        backtrack(pos, 0, res);
        return res;
    }
private: 
    void backtrack(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) {res++; return;}
        for (int col = 0; col < n; col++) {
            if (isNotUnderAttack(pos, row, col)) {
                pos[row] = col;
                backtrack(pos, row + 1, res);
                pos[row] = -1;
            }
        }
    }

    bool isNotUnderAttack(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || row - i == abs(col - pos[i])) return false;
        }
        return true;
    }
};

int main() {
    int n = 4;
    Solution sol;
    cout << sol.totalNQueens(n) << endl;

    return 0;
}