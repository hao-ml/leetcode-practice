from typing import List
from math import ceil

class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n = len(dist)
        if n - 1 >= hour:
            return -1
        max_speed = ceil(dist[n - 1] / (hour - n + 1))
        print(f"max speed: {max_speed}")

        # use for-loop, but got "Output Limit Exceeded"
        for speed in range(1, max_speed + 1):
            print(f"speed: {speed}")
            total_hour = 0
            for i, d in enumerate(dist):
                if i < n - 1:
                    h = ceil(d / speed)
                else:
                    h = d / speed
                total_hour += h
                print(f"total hour: {total_hour}")
                if total_hour > hour:
                    break
            if total_hour <= hour:
                return speed
        
        return -1
    
# test 
sol = Solution()

dist = [1,3,2]
# hour = 6
# hour = 2.7
hour = 1.9

print(sol.minSpeedOnTime(dist, hour))
