#!/usr/bin/python3
"""Module that performs the locboxes algrithm"""


def canUnlockAll(boxes):
    """Checks if lockboxes in a list can be opened"""
    n_boxes = set(range(0, len(boxes)))
    keys = set(boxes[0])
    opened_boxes = set({0})
    while len(keys - opened_boxes) > 0:
        box = (keys - opened_boxes).pop()
        opened_boxes.add(box)
        try:
            keys.update(boxes[box])
        except:
            pass
    if len(n_boxes - opened_boxes) == 0:
        return True
    else:
        return False
