from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        if image[sr][sc] == color:
            return image
        
        num_r = len(image)
        num_c = len(image[0])
        old_color = image[sr][sc]

        stack = [(sr, sc)]
        image[sr][sc] = color

        while stack:
            i, j = stack.pop()
            if i >= 1 and image[i - 1][j] == old_color:
                stack.append((i - 1, j))
                image[i - 1][j] = color
            if j >= 1 and image[i][j - 1] == old_color:
                stack.append((i, j - 1))
                image[i][j - 1] = color
            if i < num_r - 1 and image[i + 1][j] == old_color: 
                stack.append((i + 1, j))
                image[i + 1][j] = color
            if j < num_c - 1 and image[i][j + 1] == old_color:
                stack.append((i, j + 1))
                image[i][j + 1] = color

        return image