#!/usr/bin/python3
"""Module that performs the locboxes algrithm"""


def canUnlockAll(boxes):
    """Checks if lockboxes in a list can be opened"""
    i = 0
    keys = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        for j in join(boxes, keys[i:]):
            if j not in keys:
                keys.append(j)
                i += 1
                added = True
    return len(keys) == len(boxes)


def join(boxes, keys):
    """Return number of locboxes that can be opened"""
    box = []
    for key in keys:
        box += boxes[key]
    return box
