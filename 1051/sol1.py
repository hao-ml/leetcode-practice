from typing import List

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        count = 0
        for i, n in enumerate(expected):
            if n != heights[i]:
                count += 1
        
        return count

# test cases
# heights = [1,1,4,2,1,3]
# heights = [5,1,2,3,4]
heights = [1,2,3,4,5]

# test
sol = Solution()
print(sol.heightChecker(heights))