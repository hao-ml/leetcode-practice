from typing import List

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        for n in nums:
            if len(str(n)) & 1 == 0:
                res += 1

        return res

# test cases
nums = [12,345,2,6,7896]

# test
sol = Solution()
print(sol.findNumbers(nums))