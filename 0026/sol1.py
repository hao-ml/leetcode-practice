from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        temp = None
        i = 0
        for n in nums:
            if n != temp:
                nums[i] = n
                i += 1
                temp = n
        return i

# test cases
# nums = [1,1,2]
nums = [0,0,1,1,1,2,2,3,3,4]

# test 
sol = Solution()
print(sol.removeDuplicates(nums))