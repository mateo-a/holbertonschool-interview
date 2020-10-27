#!/usr/bin/python3
"""Program that solves the N queens problem."""

from sys import argv, exit


def solution(n):
    """Solution"""
    res = []

    def boardPosition(row, left, right, m, arr):
        """ Check Board Positions"""
        if row == n:
            res.append(arr)
        else:
            left = left[1:] + [0]
            right = [0] + right[:-1]
            for col in range(n):
                if m[col] == left[col] == right[col] == 0:
                    left[col] = right[col] = m[col] = 1
                    pair = [] + arr
                    pair.append([row, col])
                    boardPosition(row + 1, left, right, m, pair)
                    left[col] = right[col] = m[col] = 0

    boardPosition(0, [0] * n, [0] * n, [0] * n, [])

    for positions in res:
        print(positions)


if __name__ == "__main__":
    if len(argv) is not 2:
        print("Usage: nqueens N")
        exit(1)
    elif argv[1].isdigit() is not True:
        print("N must be a number")
        exit(1)
    elif int(argv[1]) < 4:
        print("N must be at least 4")
        exit(1)

    solution(int(argv[1]))
