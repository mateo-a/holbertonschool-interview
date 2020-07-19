#!/usr/bin/python3
'''Method that determines if all the boxes can be opened. n number of boxes,
eacho box is numbered sequentially from 0 to n-1 and each box may contain
keys to the other boxes.'''


def canUnlockAll(boxes):
    '''Check if all the boxes can be opened'''
    if (type(boxes) is not list) or (len(boxes) == 0):
        return False

    checkBox = [0] * len(boxes)
    checkBox[0] = 1
    check = [0]

    while check:
        keys = check.pop()
        for key in boxes[keys]:
            if key < len(boxes):
                if not checkBox[key]:
                    checkBox[key] = 1
                    check.append(key)
    return all(checkBox)
