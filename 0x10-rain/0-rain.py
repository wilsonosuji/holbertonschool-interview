#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ Given a list of non-negative integers
    representing walls of width 1, calculate how
    much water will be retained after it rains """
    if not walls:
        return 0
    max_list = max(walls)
    count = 0
    for x in range(max_list):
        list_2 = valid(walls)
        for i in list_2:
            if i <= 0:
                count += 1
        walls = [elem - 1 for elem in list_2]
    return count


def valid(walls):
    list_1 = []
    a = 0
    for y in walls:
        if y <= 0 and a == 0:
            continue
        list_1.append(y)
        a = 1
    list_2 = []
    a = 0
    for z in reversed(list_1):
        if z <= 0 and a == 0:
            continue
        list_2.append(z)
        a = 1
    return list_2
