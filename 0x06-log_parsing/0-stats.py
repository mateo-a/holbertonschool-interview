#!/usr/bin/python3

""" Script that reads stdin line by line and computes metrics """

import sys


def printStatistics(statusCode, fileSize):
    """ Function to print statistics """
    print("File size: {:d}".format(fileSize))
    for i in sorted(statusCode.keys()):
        if statusCode[i] != 0:
            print("{}: {:d}".format(i, statusCode[i]))


statusCodes = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
statusCounter = 0
fileSize = 0

try:
    for line in sys.stdin:
        if statusCounter != 0 and statusCounter % 10 == 0:
            printStatistics(statusCodes, fileSize)
        statusList = line.split()
        statusCounter += 1
        try:
            fileSize += int(statusList[-1])
        except:
            pass
        try:
            if statusList[-2] in statusCodes:
                statusCodes[statusList[-2]] += 1
        except:
            pass
    printStatistics(statusCodes, fileSize)

except KeyboardInterrupt:
    printStatistics(statusCodes, fileSize)
    raise
