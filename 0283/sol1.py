from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        fast = 0
        while slow < len(nums) and fast < len(nums):
            if nums[slow] != 0:
                slow += 1
            else:
                if fast == 0:
                    fast = slow + 1
                while fast < len(nums) and nums[fast] == 0:
                    fast += 1
                if fast >= len(nums):
                    break
                else:
                    temp = nums[slow]
                    nums[slow] = nums[fast]
                    nums[fast] = temp
                    slow += 1

# test cases
nums = [0,1,0,3,12]
# nums = [0]

# test
sol = Solution()
sol.moveZeroes(nums)
print(nums)