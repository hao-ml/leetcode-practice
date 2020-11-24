
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int r1 = 0; r1 * r1 <= n; r1++) {
            int r2 = sqrt(n - r1 * r1);
            if (r1 * r1 + r2 * r2 == n) return !!r1 + !!r2;
        }

        return 3;
    }
};

int main() {
    int n = 12;
    Solution sol;

    cout << sol.numSquares(n) << endl;

    return 0;
}