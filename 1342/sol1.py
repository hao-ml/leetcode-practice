class Solution:
    def numberOfSteps(self, num: int) -> int:
        num_steps = 0
        while num != 0:
            if num % 2 == 0:
                num /= 2
            else:
                num -= 1
            num_steps += 1

        return num_steps

# test cases
num = 14

# test 
sol = Solution()
print(sol.numberOfSteps(num))