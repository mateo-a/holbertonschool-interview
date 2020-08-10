#!/usr/bin/python3
""" Given a number n, calculates the fewest number of operations needed
to result in exactly n H characters in the file.
"""


def minOperations(n):
    if n < 2:
        return(0)

    div = 2
    res = 0

    while n >= div:
        if n % div == 0:
            n /= div
            res += div
            div = 1
        div += 1
    return(res)
