"""
Q1. You are given a string S. 
	Count the number of occurrences of all the digits in the string S

"""
num = "177150"
a = 0
b = 0
c = 0
d = 0
e = 0
f = 0
g = 0
h = 0
i = 0
j = 0
def match(seq, item):
	count = 0
	for i in seq:
		if item==i:
			count += 1
	return count
print "0: ", match(num, "0")
print "1: ", match(num, "1")
print "2: ", match(num, "2")
print "3: ", match(num, "3")
print "4: ", match(num, "4")
print "5: ", match(num, "5")
print "6: ", match(num, "6")
print "7: ", match(num, "7")
print "8: ", match(num, "8")
print "9: ", match(num, "9")