from math import *
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for x in range(ceil(n/2)):
            for y in range(floor(n/2)):
                matrix[y][x], matrix[x][n-1-y], matrix[n-1-y][n-1-x], matrix[n-1-x][y] = matrix[n-1-x][y], matrix[y][x], matrix[x][n-1-y], matrix[n-1-y][n-1-x]

