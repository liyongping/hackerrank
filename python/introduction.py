''' input
a = int(raw_input())
b = int(raw_input())

print a+b
print a-b
print a*b
'''


''' Divison
from __future__ import division

print 4/3
print 4//3

'''


''' loops
n = int(raw_input())

for i in range(0,n):
	print i*i
'''


''' Finding the percentage
from __future__ import division

dict = {}
student_number = int(raw_input())

for x in range(0,student_number):
	name, math, physics, chemistry= raw_input().split()
	dict[name] = [float(math), float(physics), float(chemistry)]

student_name = raw_input()

print "%.2f" % (sum(dict[student_name])/3)
'''

''' Divmode
a = int(raw_input())
b = int(raw_input())

t = divmod(a,b)
print t[0]
print t[1]
print t
'''

''' What's Your Name?
first_name = raw_input()
last_name = raw_input()

print "Hello %s %s! You just delved into python." % (first_name,last_name)
''' 

''' Mode Power
a = int(raw_input())
b = int(raw_input())
m = int(raw_input())

print pow(a,b)
print pow(a,b,m)
'''

''' Triangle Quest
for i in range(1,input()): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print 111111111*i/(10**(9-i))
    #print int(str(i)*i)

'''

a = int(raw_input())
b = int(raw_input())

c,d = (a,b)

print d
print c

