from typing import List

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res = []
        for i in range(n):
            if (i + 1) % 15 == 0:
                res.append("FizzBuzz")
            elif (i + 1) % 3 == 0:
                res.append("Fizz")
            elif (i + 1) % 5 == 0:
                res.append("Buzz")
            else:
                res.append(str(i + 1))

        return res

# test cases
# n = 3
# n = 5
n = 15

# test
sol = Solution()
print(sol.fizzBuzz(n))