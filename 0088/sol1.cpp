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
        vector<int> nums(m + n);
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < m && j < n) {
            int num1 = nums1.at(i);
            int num2 = nums2.at(j);
            if (num1 < num2) {
                nums.at(k) = num1;
                i++;
            }
            else {
                nums.at(k) = num2;
                j++;
            }
            k++; 
        }

        if (i < m) {
            nums.insert(nums.begin()+k, nums1.begin()+i, nums1.end());
        }

        if (j < n) {
            nums.insert(nums.begin()+k, nums2.begin()+j, nums2.end());
        }

        nums1.assign(nums.begin(), nums.begin()+m+n);

    }
};

int main() {

    int m;
    cin >> m;
    vector<int> nums1(m);
    for (int i = 0; i < m; i++) {
        cin >> nums1.at(i);
    }
    
    int n;
    cin >> n;
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) {
        cin >> nums2.at(i);
    }

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    printVector(nums1);

    return 0;
  
}