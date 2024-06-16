import math
class Solution(object):
    def kthFactor(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        
        i = 1
        total = 0
        while i < math.sqrt(n):
            if n % i == 0:
                total += 1
            i += 1
        total *= 2
        if math.sqrt(n) == i:
            total += 1
            if k == total // 2 + 1:
                return i
            
        i = 1
        j = 0
        while i < math.sqrt(n):
            if n % i == 0:
                j += 1
                if j == k:
                    return i
                elif total + 1 - j == k:
                    return int(n / i)
            i += 1

        return -1

    
sol = Solution()

# test cases
n = 12
k = 3
# n = 7
# k = 2
# n = 4
# k = 4

print(sol.kthFactor(n, k))
