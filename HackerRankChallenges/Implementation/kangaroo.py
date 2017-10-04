# Statement: https://www.hackerrank.com/challenges/kangaroo

#!/bin/python
import sys

def kangaroo(x1, v1, x2, v2):
    if(x2>x1 and v2>v1):
        return "NO"
    else:
        for i in range(10000):
            x1+=v1
            x2+=v2
            if(x1==x2):
                return "YES"
        return "NO"
x1, v1, x2, v2 = raw_input().strip().split(' ')
x1, v1, x2, v2 = [int(x1), int(v1), int(x2), int(v2)]
result = kangaroo(x1, v1, x2, v2)
print(result)
