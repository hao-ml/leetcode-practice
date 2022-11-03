from typing import List

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        i = 0
        while i < len(nums):
            if nums[i] == i + 1 or nums[i] == 0:
                i += 1
            else:
                if nums[nums[i] - 1] == nums[i]:
                    nums[i] = 0
                    i += 1
                else:
                    temp = nums[nums[i] - 1]
                    nums[nums[i] - 1] = nums[i]
                    nums[i] = temp

        res = []
        for i, n in enumerate(nums):
            if n == 0:
                res.append(i + 1)
        
        return res

# test cases
# nums = [4,3,2,7,8,2,3,1]
nums = [1,1]

# test 
sol = Solution()
print(sol.findDisappearedNumbers(nums))