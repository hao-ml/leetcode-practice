class Solution:
    def numberOfSteps(self, num: int) -> int:
        num_steps = 0
        while num != 0:
            if num & 1 == 0:
                num >>= 1
            else:
                num -= 1
            num_steps += 1

        return num_steps

# test cases
# num = 14
num = 123

# test 
sol = Solution()
print(sol.numberOfSteps(num))