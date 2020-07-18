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
    i = 0

    for keys in boxes:
        for key in keys:
            if (len(keys) == 1):
                if ((boxes[i][0] == i) and (i < len(boxes) - 1)):
                    return False
            if (checkBox[key] == 0):
                checkBox[key] = 1
        i += 1
    if (checkBox.count(1) == len(boxes)):
        return True
    else:
        return False
