class Solution(object):
    def kthFactor(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        
        j = 0
        for i in range(1, n + 1):
            if n % i == 0:
                j += 1
                if j == k:
                    return i
        return -1
    
sol = Solution()

# test cases
# n = 12
# k = 3
# n = 7
# k = 2
n = 4
k = 4

print(sol.kthFactor(n, k))
