#!/usr/bin/python3
"""
Function that returns a list of lists of integers
representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers for the Pascal's triangle
    """
    triangle = []
    for i in range(n):
        temp = [1]
        if i > 0:
            for j in range(len(triangle)):
                if j == len(triangle) - 1:
                    temp.append(1)
                else:
                    temp.append(triangle[i - 1][j] + triangle[i - 1][j + 1])
        triangle.append(temp)
    return triangle
