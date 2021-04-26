#!/usr/bin/python3
""" Prime Game """


def _isPrime(n):
    _prime = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not _prime[i]:
            continue
        for j in range(i*i, n + 1, i):
            _prime[j] = False

    _prime[0] = _prime[1] = False
    c = 0
    for i in range(len(_prime)):
        if _prime[i]:
            c += 1
        _prime[i] = c
    return _prime


def isWinner(x, nums):
    """ Prime Game"""
    if not nums or x < 1:
        return None
    n = max(nums)
    _prime = _isPrime(n)

    player1 = 0
    for n in nums:
        player1 += _prime[n] % 2 == 1
    if player1 * 2 == len(nums):
        return None
    if player1 * 2 < len(nums):
        return "Ben"
    return "Maria"
