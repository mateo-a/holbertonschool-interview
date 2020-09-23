#!/usr/bin/python3
'''
Method that determines if a given data set represents a
valid UTF-8 encoding.
'''


def validUTF8(data):
    '''Method to validate UTF-8 encoding'''
    numBytes = 0
    check8 = 1 << 7
    check7 = 1 << 6

    for num in data:
        check = 1 << 7
        if numBytes == 0:
            while check & num:
                numBytes += 1
                check = check >> 1
            if numBytes == 0:
                continue
            if numBytes == 1 or numBytes > 4:
                return False
        else:
            if not (num & check8 and not (num & check7)):
                return False
        numBytes -= 1
    return numBytes == 0
