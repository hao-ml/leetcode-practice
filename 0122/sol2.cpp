#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int dPrice = prices.at(i) - prices.at(i-1);
            if (dPrice > 0) {
                profit += dPrice;
            } 
        }

        return profit;
    }
};

void printVector(vector<int> &vec) {
    for (int v : vec) {
        cout << v << ' ';
    }
    cout << endl;
}

int main() {
    
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices.at(i);
    }

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
  
}
