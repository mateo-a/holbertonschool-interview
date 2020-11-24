#!/usr/bin/python3
""" Rain Excercise """


def rain(walls):
    """ Rain Excercise """

    if not walls or not isinstance(walls, list):
        return 0

    """l, water = len(walls), 0"""
    water = 0
    bef = [0] * len(walls)
    aft = [0] * len(walls)

    bef[0], aft[len(walls) - 1] = walls[0], walls[len(walls) - 1]

    x = 1
    y = len(walls) - 2

    while True:
        if x >= len(walls) or y <= -1:
            break
        bef[x] = max(bef[x - 1], walls[x])
        aft[y] = max(aft[y + 1], walls[y])
        x += 1
        y -= 1
    for x in range(len(walls)):
        water += min(bef[x], aft[x]) - walls[x]
    return water
