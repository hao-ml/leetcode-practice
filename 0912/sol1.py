from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(nums1, nums2):
            merged = []
            i, j = 0, 0
            while i < len(nums1) and j < len(nums2):
                if nums1[i] < nums2[j]:
                    merged.append(nums1[i])
                    i += 1
                else:
                    merged.append(nums2[j])
                    j += 1
            
            while i < len(nums1):
                merged.append(nums1[i])
                i += 1
            while j < len(nums2):
                merged.append(nums2[j])
                j += 1

            return merged
        
        length = len(nums)
        if length == 1:
            return nums

        pivot = length // 2
        
        return merge(
            self.sortArray(nums[:pivot]), 
            self.sortArray(nums[pivot:]))
    
# test
sol = Solution()
nums = [5,2,3,1]
print(sol.sortArray(nums))
