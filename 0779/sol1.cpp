#include <bits/stdc++.h>
using namespace std;

// TLE: 15/55
class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<int> A(pow(2, N-1));
        helper(1, N, A);
        return A[K-1];
    }
private:
    void helper(int n, int &N, vector<int> &A) {
        if (n > N) return;
        if (n == 1) A[0] = 0;
        else if (n == 2) A[1] = 1;
        else {
            int len1 = pow(2, n - 2);
            int len2 = pow(2, n - 1);
            for (int i = 0; i < len1/2; i++) {
                if (A[len1/2 + i] == 0) {
                    A[len2/2 + 2*i] = 0;
                    A[len2/2 + 2*i + 1] = 1;
                }
                else {
                    A[len2/2 + 2*i] = 1;
                    A[len2/2 + 2*i + 1] = 0;
                }
            }
        }
        helper(n + 1, N, A);
    }
};

int main() {
    // int N = 1, K = 1;
    int N = 30, K = 434991989;
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