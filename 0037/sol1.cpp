#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<char>> &mat) {
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
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
private: 
    bool backtrack(vector<vector<char>> &board, int row, int col) {
        int n = board.size();
        if (row == n) return true;
        if (col == n) return backtrack(board, row + 1, 0);
        if (board[row][col] != '.') return backtrack(board, row, col + 1);
        for (int d = 1; d <= n; d++) {
            if (isValid(board, row, col, d)) {
                char c = '0' + d;
                board[row][col] = c;
                if (backtrack(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, int d) {
        int n = board.size();
        char c = '0' + d;
        for (int i = 0; i < n; ++i) {
            if (board[row][i] == c || board[i][col] == c) return false;
        }
        int root = sqrt(n);
        int row0 = row / root * root, col0 = col / root * root;
        for (int i = row0; i < row0 + root; i++) {
            for (int j = col0; j < col0 + root; j++) {
                if (board[i][j] == c) return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    // vector<vector<char>> board = {
    //     {'1','2','3','4'},
    //     {'3','.','1','2'},
    //     {'2','1','.','3'},
    //     {'4','3','2','1'}};
    printMatrix(board);
    Solution sol;
    sol.solveSudoku(board);
    cout << "Solved!" << endl;
    printMatrix(board);

    return 0;
}