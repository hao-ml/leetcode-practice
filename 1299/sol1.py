from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        current_max = -1

        for i, n in reversed(list(enumerate(arr))):
            arr[i] = current_max
            if current_max < n:
                current_max = n

        return arr

# test cases
# arr = [17,18,5,4,6,1]
arr = [400]

# test 
sol = Solution()
print(sol.replaceElements(arr))