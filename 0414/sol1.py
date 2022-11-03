from typing import List

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        min_num = None
        for n in nums:
            if min_num is None:
                min_num = n
            else:
                if n < min_num:
                    min_num = n
        
        firstMax = min_num
        secondMax = firstMax
        thirdMax = firstMax

        for i in range(len(nums)):
            if nums[i] > firstMax:
                thirdMax = secondMax
                secondMax = firstMax
                firstMax = nums[i]
            elif nums[i] > secondMax:
                if nums[i] != firstMax:
                    thirdMax = secondMax
                    secondMax = nums[i]
            elif nums[i] > thirdMax:
                if nums[i] != secondMax:
                    thirdMax = nums[i]

        if firstMax == secondMax or secondMax == thirdMax:
            return firstMax
        else:
            return thirdMax

# test cases
# nums = [3,2,1]
# nums = [1,2]
# nums = [2,2,3,1]
nums = [1,2,2,5,3,5]

# test
sol = Solution()
print(sol.thirdMax(nums))