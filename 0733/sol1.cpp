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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty()) return image;
        int oldColor = image[sr][sc];
        if (newColor == oldColor) return image;
        int nr = image.size(), nc = image[0].size();
        stack<pair<int, int>> stk;
        stk.push({sr, sc});
        image[sr][sc] = newColor;
        while(!stk.empty()) {
            int r = stk.top().first, c = stk.top().second; stk.pop();
            if (r - 1 >= 0 && image[r - 1][c] == oldColor) {
                stk.push({r - 1, c});
                image[r - 1][c] = newColor;
            }
            if (r + 1 < nr && image[r + 1][c] == oldColor) {
                stk.push({r + 1, c});
                image[r + 1][c] = newColor;
            }
            if (c - 1 >= 0 && image[r][c - 1] == oldColor) {
                stk.push({r, c - 1});
                image[r][c - 1] = newColor;
            }
            if (c + 1 < nc && image[r][c + 1] == oldColor) {
                stk.push({r, c + 1});
                image[r][c + 1] = newColor;
            }
        }
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    cout << "Image:" << endl; printMatrix(image);
    Solution sol;
    auto ans = sol.floodFill(image, sr, sc, newColor);
    cout << "Modified:" << endl; printMatrix(ans);

    return 0;
} 