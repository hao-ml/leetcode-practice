from typing import List
from numpy import random

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.quick_sort(nums, 0, len(nums) - 1)
        return nums

    def quick_sort(self, nums, left, right):
        if left >= right:
            return
        
        pivot = nums[random.randint(left, right)]
        i, j = left, right
        while i <= j:
            while i < right and nums[i] < pivot:
                i += 1
            while j > left and nums[j] > pivot:
                j -= 1
            if i <= j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        self.quick_sort(nums, left, j)
        self.quick_sort(nums, i, right)