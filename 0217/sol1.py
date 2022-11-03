from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set()

        for n in nums:
            if n not in s:
                s.add(n)
            else:
                return True
        
        return False

# test cases
# nums = [1,2,3,1]
# nums = [1,2,3,4]
nums = [1,1,1,3,3,4,3,2,4,2]

# test 
sol = Solution()
print(sol.containsDuplicate(nums))