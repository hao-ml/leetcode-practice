class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        start, end = 0, len(nums) - 1
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] > target:
                end = mid - 1
            elif nums[mid] < target:
                start = mid + 1
            else:
                first, last = mid, mid
                while first - 1 >= 0:
                    if nums[first - 1] == target:
                        first -= 1
                    else:
                        break
                while last + 1 < len(nums):
                    if nums[last + 1] == target:
                        last += 1
                    else: 
                        break
                return first, last
        
        return -1, -1

sol = Solution()

# test cases
# nums = [5,7,7,8,8,10]
# target = 8
# nums = [5,7,7,8,8,10]
# target = 6
nums = []
target = 0

print(sol.searchRange(nums, target))
