class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for num in nums:
            if i < 2 or num > nums[i - 2]:
                nums[i] = num
                i += 1
        return i

# test cases
# nums = [1,1,2]
nums = [0,0,1,1,1,2,2,3,3,4]

# test 
sol = Solution()
print(sol.removeDuplicates(nums))