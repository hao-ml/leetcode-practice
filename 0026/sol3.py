class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 1
        while i < len(nums):
            if nums[i] == nums[i - 1]:
                nums.pop(i)
            else:
                i += 1
        return len(nums)
    

# test cases
# nums = [1,1,2]
nums = [0,0,1,1,1,2,2,3,3,4]

# test 
sol = Solution()
print(sol.removeDuplicates(nums))