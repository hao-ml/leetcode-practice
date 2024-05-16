class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp = None
        count = 0
        i = 0
        for num in nums:
            if num != temp:
                if count != 0:
                    count = 0
                nums[i] = num
                i += 1
                temp = num
                count += 1
            else:
                if count < 2:
                    nums[i] = num
                    i += 1
                    temp = num
                    count += 1
            
        return i

# test cases
# nums = [1,1,2]
nums = [0,0,1,1,1,2,2,3,3,4]

# test 
sol = Solution()
print(sol.removeDuplicates(nums))