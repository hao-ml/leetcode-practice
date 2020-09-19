#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n -1;

        while(j >= 0 && i >= 0) {
            int num1 = nums1.at(i);
            int num2 = nums2.at(j);
            if (num1 > num2) {
                nums1.at(k) = num1;
                i--;
            }
            else {
                nums1.at(k) = num2;
                j--;
            }
            k--;
        }

        while(j >= 0) {
            nums1.at(k) = nums2.at(j);
            k--;
            j--;
        }

    }
};

int main() {

    int m;
    cin >> m;

    int n;
    cin >> n;
    
    vector<int> nums1(m+n, 0);
    for (int i = 0; i < m; i++) {
        cin >> nums1.at(i);
    }
    
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2.at(i);
    }

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    printVector(nums1);

    return 0;
  
}