from typing import List
from math import ceil

class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        n = len(dist)
        if n - 1 >= hour:
            return -1
        max_speed = ceil(dist[n - 1] / (hour - n + 1))
        max_speed = max([*dist, max_speed])
        print(f"max speed: {max_speed}")

        # binary search
        start, end = 1, max_speed
        min_speed = max_speed
        min_speed_hour = n - 1 + (dist[n - 1] / min_speed)
        while start <= end:
            speed = (start + end) // 2
            total_hour = 0
            for i, d in enumerate(dist):
                if i < n - 1:
                    h = ceil(d / speed)
                else:
                    h = d / speed
                total_hour += h
                if total_hour > hour:
                    break
            if total_hour > hour:
                start = speed + 1
            else:
                end = speed - 1
                if speed <= min_speed:
                    min_speed = speed
                    min_speed_hour = total_hour

        if min_speed_hour > hour:
            return -1
        else:
            return min_speed
    
    
# test 
sol = Solution()

dist = [1,3,2]
# hour = 6
# hour = 2.7
hour = 1.9

dist = [5,3,4,6,2,2,7]
hour = 10.92

print(sol.minSpeedOnTime(dist, hour))
