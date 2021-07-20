#!/usr/bin/python3

def canUnlockAll(boxes):
  i = 0
  total = list(set(boxes[0]) | {0})
  added = True
  while added:
    added = False
    for j in join(boxes, total[i:]):
      if j not in total:
        total.append(j)
        i += 1
        added= True
  return len(total)==len(boxes)

def join(T, R):
  res = []
  for e in R:
    res += T[e]
  return res
