class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        n = len(nums)
        k %= n

        i = n - k
        nums[:] = nums[i:] + nums[:i]

# test cases
sol = Solution()
nums = [-1,-100,3,99]
k = 2
sol.rotate(nums, k)

print(
    nums
)