#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int ans = kthGrammar(N - 1, (K + 1) / 2);
        return (K % 2) ? ans : (1 - ans);
    }
};

int main() {
    int N = 4, K = 5;
    // int N = 30, K = 434991989;
    Solution sol;
    cout << sol.kthGrammar(N, K) << endl;

    return 0;
}

/*
0
01
0110
01101001
0110100110010110
*/