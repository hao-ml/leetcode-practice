from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = len(nums) - 1
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                k += 1
            else:
                while nums[j] == val and j >= 0:
                    j -= 1
                if j <= i:
                    break
                nums[i] = nums[j]
                nums[j] = val
                k += 1

        return k

# test cases
# nums = [3,2,2,3]
# val = 3
nums = [0,1,2,2,3,0,4,2]
val = 2

# test 
sol = Solution()
print(sol.removeElement(nums, val))
print(nums)