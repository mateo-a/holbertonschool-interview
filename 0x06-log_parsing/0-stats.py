#!/usr/bin/python3
"""

Function that inserts a line of text to a file, after each line containing
a specific string

"""


def append_after(filename="", search_string="", new_string=""):
    """
    Inserts a line of text to a file, after each line containing a
    specific string
    Arguments:
       filename (file): file
       search_string (str): string
       new_string (str): string
    """
    new = ""
    with open(filename, mode="r+", encoding="utf-8") as f:
        for line in f:
            new += line
            if search_string in line:
                new += new_string
        f.seek(0)
        f.write(new)
