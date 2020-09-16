#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        int buy = prices.at(0);
        int sell = prices.at(0);
        for (int i = 1; i < prices.size(); i++) {
            if (prices.at(i) < sell) {
                profit += (sell - buy);
                buy = prices.at(i);
                sell = prices.at(i);
            }
            else {
                sell = prices.at(i);
            }
        }

        profit += (sell - buy);

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
