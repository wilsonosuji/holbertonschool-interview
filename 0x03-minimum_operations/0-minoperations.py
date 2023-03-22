#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    count = 0
    add = 1
    tmp = 0

    if n < 2:
        return 0

    while add < n:
        if n % add == 0:
            tmp = add
            add *= 2
            count += 1
        else:
            add += tmp
        count += 1
    return count
