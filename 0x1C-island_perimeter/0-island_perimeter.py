#!/usr/bin/python3
"""
Function that returns the perimeter of the island
described in grid
"""


def island_perimeter(grid):
    """Find the perimeter"""
    count = 0

    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                count += 4
                if x > 0 and grid[x - 1][y] == 1:
                    count -= 2
                if y > 0 and grid[x][y - 1] == 1:
                    count -= 2
    return count
