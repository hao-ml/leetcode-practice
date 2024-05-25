class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        n = len(nums)
        k %= n

        def reverse(i, j):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        
        reverse(0, n - k - 1)
        reverse(n - k, n - 1)
        reverse(0, n - 1)

# test cases
sol = Solution()
nums = [-1,-100,3,99]
k = 2
sol.rotate(nums, k)

print(
    nums
)