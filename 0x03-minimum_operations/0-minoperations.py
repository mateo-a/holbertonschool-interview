#!/usr/bin/python3
import math
""" Given a number n, calculates the fewest number of operations needed
to result in exactly n H characters in the file.
"""


def minOperations(n):
    res = 0

    if n <= 1:
        return res

    while n % 2 == 0:
        res += 2
        n = n / 2

    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            res += i
            n = n / i

    if n > 2:
        res += n

    return (int(res))
