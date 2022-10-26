from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_con = 0
        count = 0

        for n in nums:
            if n == 1:
                count += 1
            else:
                if count > max_con:
                    max_con = count
                count = 0
        if count > max_con:
            max_con = count

        return max_con

# test cases
# nums = [1,1,0,1,1,1]
nums = [1,0,1,1,0,1]

# test 
sol = Solution()
print(sol.findMaxConsecutiveOnes(nums))