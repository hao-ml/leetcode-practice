#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        while (!nums1.empty() && !nums2.empty()) {
            bool isFound = false;
            for (int i = 0; i < nums1.size(); i++) {
              for (int j = 0; j < nums2.size(); j++) {
                if (nums1.at(i) == nums2.at(j)) {
                  ans.push_back(nums1.at(i));
                  nums2.erase(nums2.begin() + j);
                  isFound = true;
                  break;
                }
              }
              if (isFound) {
                nums1.erase(nums1.begin() + i);
                break;
              }
            }
            if (!isFound) {
              break;
            }
          }
        return ans;
    }
};

int main() {

    int n1;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> nums1.at(i);
    }

    int n2;
    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> nums2.at(i);
    }

    Solution sol;
    vector<int> ans;
    ans = sol.intersect(nums1, nums2);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << ' ';
    }
    cout << endl;

    return 0;
  
}
