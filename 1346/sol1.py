from typing import List

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        ht = {}
        
        for i, n in enumerate(arr):
            if n not in ht.keys():
                ht[n] = i
            if 2 * n in ht.keys() and ht[2 * n] != i:
                return True
            if n / 2 in ht.keys() and ht[n / 2] != i:
                return True
        
        return False

# test cases
# arr = [10,2,5,3]
# arr = [3,1,7,11]
arr = [-2,0,10,-19,4,6,-8]

# test
sol = Solution()
print(sol.checkIfExist(arr))