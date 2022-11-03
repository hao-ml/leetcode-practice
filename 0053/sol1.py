from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = []
        dp.append(nums[0])
        max_sub = nums[0]

        for i in range(1, len(nums)):
            if dp[i - 1] < 0:
                dp.append(nums[i])
            else:
                dp.append(dp[i - 1] + nums[i])
            if dp[i] > max_sub:
                max_sub = dp[i]

        return max_sub

# test cases
# nums = [-2,1,-3,4,-1,2,1,-5,4]
# nums = [1]
nums = [5,4,-1,7,8]

# test 
sol = Solution()
print(sol.maxSubArray(nums))
        