class Solution(object):
    def partitionString(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        appeared = set()
        num = 0
        for char in s:
            if char not in appeared:
                appeared.add(char)
            else:
                num += 1
                appeared = set()
                appeared.add(char)
        
        if appeared:
            return num + 1
        else:
            return num
        
sol = Solution()

# test cases
s = "abacaba"
s = "ssssss"

print(sol.partitionString(s))