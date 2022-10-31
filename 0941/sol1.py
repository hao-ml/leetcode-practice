from typing import List

class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False
        
        peak_reached = False
        i = 0

        while i < len(arr) - 1:
            if not peak_reached:
                if arr[i] < arr[i + 1]:
                    i += 1
                elif arr[i] > arr[i + 1]:
                    if i == 0:
                        return False
                    peak_reached = True
                    i += 1
                else:
                    return False
            else:
                if arr[i] <= arr[i + 1]:
                    return False
                else:
                    i += 1

        if not peak_reached:
            return False

        return True

# test cases
# arr = [2,1]
# arr = [3,5,5]
# arr = [0,3,2,1]
# arr = [0,1,2,3,4,5,6,7,8,9]
# arr = [0,3,2,1]
arr = [9,8,7,6,5,4,3,2,1,0]

# test
sol = Solution()
print(sol.validMountainArray(arr))