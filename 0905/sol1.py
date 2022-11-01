from typing import List

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        i = 0
        j = len(nums) - 1

        while i < j:
            if nums[i] & 1 == 0:
                i += 1
            else:
                while i < j and nums[j] & 1 == 1:
                    j -= 1
                if i < j:
                    temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
                    i += 1
                    j -= 1

        return nums

# test cases
# nums = [3,1,2,4]
nums = [0]

# test
sol = Solution()
print(sol.sortArrayByParity(nums))