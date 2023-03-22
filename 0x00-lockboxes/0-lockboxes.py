#!/usr/bin/python3


def canUnlockAll(boxes):

    keys = [0]

    for x in keys:
        for y in boxes[x]:
            if y < len(boxes) and y not in keys:
                keys.append(y)
    if len(boxes) == len(keys):
        return True
    return False
