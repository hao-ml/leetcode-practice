from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        if numRows == 1:
            return ans
        ans.append([1, 1])
        if numRows == 2:
            return ans
        for n in range(3, numRows + 1):
            prev_row = ans[-1]
            new_row = [1]
            for i in range(1, n - 1):
                new_row.append(prev_row[i - 1] + prev_row[i])
            new_row.append(1)
            ans.append(new_row)

        return ans
    
# test
sol = Solution()

print(sol.generate(5))
