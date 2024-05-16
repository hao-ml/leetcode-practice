from collections import defaultdict

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)
        m = defaultdict(int)

        for num in nums:
            m[num] += 1
        
        for key, value in m.items():
            if value > n // 2:
                return key

        return 0    

# test cases
nums = [1]
# nums = [3,2,3]
# nums = [2,2,1,1,1,2,2]

# test 
sol = Solution()
print(sol.majorityElement(nums))