from typing import List

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max_wealth = 0
        for i in range(len(accounts)):
            wealth = 0
            for j in range(len(accounts[i])):
                wealth += accounts[i][j]
            if wealth > max_wealth:
                max_wealth = wealth
        
        return max_wealth

# test cases
# accounts = [[1,2,3],[3,2,1]]
accounts = [[1,5],[7,3],[3,5]]

# test 
sol = Solution()
print(sol.maximumWealth(accounts))