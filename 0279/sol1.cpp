
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int root = 1;
        int ans = 1;
        queue<int> q;
        
        while (root * root <= n) {
            q.push(root * root);
            root++;
        }
        root--;
        
        if (root * root == n) return 1;

        while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int sum = q.front(); q.pop();
                for (int r = 1; r <= root; r++) {
                    if (r * r + sum == n) return ans + 1;
                    else if (r * r + sum < n) q.push(r * r + sum);
                }
            }
            ans++;
        }

        return 0;
    }
};

int main() {
    int n = 12;
    Solution sol;

    cout << sol.numSquares(n) << endl;

    return 0;
}