from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        min_abs = abs(nums[0])
        min_i = 0
        for i, n in enumerate(nums):
            if abs(n) < min_abs:
                min_abs = abs(n)
                min_i = i

        res = []
        res.append(min_abs ** 2)
        left_i = min_i - 1
        right_i = min_i + 1
        while left_i >= 0 and right_i < len(nums):
            if abs(nums[left_i]) < abs(nums[right_i]):
                res.append(nums[left_i] ** 2)
                left_i -= 1
            else:
                res.append(nums[right_i] ** 2)
                right_i += 1

        while left_i >= 0:
            res.append(nums[left_i] ** 2)
            left_i -= 1

        while right_i < len(nums):
            res.append(nums[right_i] ** 2)
            right_i += 1

        return res

# test cases
# nums = [-4,-1,0,3,10]
nums = [-7,-3,2,3,11]

# test 
sol = Solution()
print(sol.sortedSquares(nums))