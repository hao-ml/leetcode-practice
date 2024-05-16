class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # Moore's Voting Algorithm
        count = 0
        candidate = 0

        for num in nums:
            if count == 0:
                candidate = num
            if num == candidate:
                count += 1
            else:
                count -= 1
        
        return candidate

# test cases
nums = [1]
# nums = [3,2,3]
# nums = [2,2,1,1,1,2,2]

# test 
sol = Solution()
print(sol.majorityElement(nums))