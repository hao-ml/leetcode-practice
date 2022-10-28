from typing import List

class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        num_zeros = 0
        for i in range(len(arr)):
            if arr[i] == 0:
                num_zeros += 1
            if num_zeros + i >= len(arr) - 1:
                break
        
        # edge case: the last zero can not be duplicated
        if arr[i] == 0 and num_zeros + i > len(arr) - 1:
            arr[-1] = 0
            i -= 1
            j = len(arr) - 2
        else:
            j = len(arr) - 1

        while i >=0 and j > i:
            if arr[i] == 0:
                arr[j] = 0
                j -= 1
                arr[j] = 0
            else:
                arr[j] = arr[i]
            i -= 1
            j -= 1
        
# test cases
# arr = [1,0,2,3,0,4,5,0]
# arr = [1,2,3]
arr = [1,5,2,0,6,8,0,6,0]

# test
sol = Solution()
sol.duplicateZeros(arr)
print(arr)