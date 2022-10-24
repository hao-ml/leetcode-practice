class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        results = []

        for i in range(len(nums)):
            if i == 0:
                results.append(nums[0])
            else:
                results.append(nums[i] + results[i - 1])
        
        return results