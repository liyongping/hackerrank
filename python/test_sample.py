# a = set('abcd')

# b = set("adef")

# l = ['c', 'b', 'e', 'f']

# print ''.join(l)

# print a^b
# 
import re
for n in range(0,input()):
    phone = raw_input()
    if re.match(r"^[789][\d]{1,14}$",phone):
    	print "True"
    else:
    	print "False"