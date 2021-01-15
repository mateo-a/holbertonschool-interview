#!/usr/bin/python3

'''Rotate 2D matrix'''


def rotate_2d_matrix(matrix):
    ''' Function to rotate 2D matrix 90 degrees clockwise'''
    temp = zip(*matrix[::-1])
    matrix.clear()
    matrix.extend([list(elem) for elem in temp])
