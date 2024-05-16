class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        nums.sort()
        n = len(nums)
        
        return nums[n//2]
    

# test cases
# nums = [1]
nums = [3,2,3]
# nums = [2,2,1,1,1,2,2]

# test 
sol = Solution()
print(sol.majorityElement(nums))