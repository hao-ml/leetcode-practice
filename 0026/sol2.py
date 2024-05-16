class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums[:] = sorted(set(nums))
        return len(nums)

# test cases
# nums = [1,1,2]
nums = [0,0,1,1,1,2,2,3,3,4]

# test 
sol = Solution()
print(sol.removeDuplicates(nums))