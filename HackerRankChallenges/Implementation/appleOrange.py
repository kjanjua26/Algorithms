#!/bin/python

import sys


s,t = raw_input().strip().split(' ')
s,t = [int(s),int(t)]
a,b = raw_input().strip().split(' ')
a,b = [int(a),int(b)]
m,n = raw_input().strip().split(' ')
m,n = [int(m),int(n)]
apple = map(int,raw_input().strip().split(' '))
orange = map(int,raw_input().strip().split(' '))

appleList = []
orangeList = []
appleCount = 0
orangeCount = 0

for i in apple:
    i = i + a
    appleList.append(i)
for i in orange:
    i = i + b
    orangeList.append(i)
for i in appleList:
    if i >= s and i <= t:
        appleCount += 1
for i in orangeList:
    if i >= s and i <= t:
        orangeCount += 1
        
        
print appleCount
print orangeCount
