''' lists
list = []

for x in range(0,input()):
	command = raw_input().split()
	if command[0] == 'insert':
		list.insert(int(command[1]),int(command[2]))
	elif command[0] == 'print':
		print list 
	elif command[0] == 'remove':
		list.remove(int(command[1]))
	elif command[0] == 'append':
		list.append(int(command[1]))
	elif command[0] == 'sort':
		list.sort()
	elif command[0] == 'pop':
		list.pop()
	elif command[0] == 'reverse':
		list.reverse()
'''

''' touples
n = int(raw_input())
p = map(int,raw_input().split())
print hash(tuple(p))
'''

''' Sets
n1 = int(raw_input())
l1 = map(int,raw_input().split())

n2 = int(raw_input())
l2 = map(int,raw_input().split())

s1 = set(l1)
s2 = set(l2)

x = sorted(list(s1.difference(s2).union(s2.difference(s1))))
for i in x:
    print i 

'''

''' list comprehensions
x = int(raw_input())+1
y = int(raw_input())+1
z = int(raw_input())+1
n = int(raw_input())

list = [ [xi,yi,zi] for xi in range(0,x) for yi in range(0,y) for zi in range(0,z) if xi+yi+zi != n]

print list

'''

''' Find second maximum number in a list
n = int(raw_input())
list_input = map(int,raw_input().split())
list_sorted = sorted(list(set(list_input)))
print list_sorted[len(list_sorted)-2]

'''

''' nested list
l = []
for n in range(0,input()):
	name = raw_input()
	mark = float(raw_input())
	l.append([name,mark])

if len(l)> 1:
    value = [s[1] for s in l]
    value_set = set(value)
    value_set.remove(min(value))

    snd_lowest_value = min(value_set)
    print snd_lowest_value

    name_list = [s[0] for s in l if s[1] == snd_lowest_value]

    for name in sorted(name_list):
        print name
else:
    print None

'''