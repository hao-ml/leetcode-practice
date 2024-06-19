from itertools import pairwise
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        def dfs(i, j):
            if (
                not 0 <= i < m
                or not 0 <= j < n
                or image[i][j] != oc
                or image[i][j] == color
            ):
                return
            image[i][j] = color
            for a, b in pairwise(dirs):
                dfs(i + a, j + b)


        m = len(image)
        n = len(image[0])
        oc = image[sr][sc]
        dirs = [-1, 0, 1, 0, -1]
        dfs(sr, sc)

        return image