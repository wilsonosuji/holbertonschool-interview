#!/usr/bin/python3
"""
Method that determines if a given
data set represents a valid UTF-8 encoding
"""


def validate(data, number, bytes):
    lists = []
    try:
        for x in range(bytes):
            lists.append(
                int("{0:b}".format((data[number + (x + 1)] & 255) >> 6)))

        for val in lists:
            if val != 10:
                return(0)
        return(bytes)
    except IndexError:
        return(0)


def validUTF8(data):
    """
    validate UTF-8
    """
    step = 0
    for number in range(len(data)):
        if step:
            step -= 1
            continue

        tmp_number = data[number] & 255
        tmp = tmp_number >> 7

        if (bin(tmp) == '0b0'):
            continue

        tmp = tmp_number >> 5
        if(int("{0:b}".format(tmp)) == 110):
            step = validate(data, number, 1)
            if step == 0:
                return('False')
            continue

        tmp = tmp_number >> 4
        if(int("{0:b}".format(tmp)) == 1110):
            step = validate(data, number, 2)
            if step == 0:
                return('False')
            continue

        tmp = tmp_number >> 3
        if(int("{0:b}".format(tmp)) == 11110):
            step = validate(data, number, 3)
            if step == 0:
                return('False')
            continue
        return('False')
    return('True')
