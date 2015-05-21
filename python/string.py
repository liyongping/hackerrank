'''
string = raw_input()
index_str,char = raw_input().split()
index = int(index_str)

print string[:index]+char+string[index+1:]

'''

'''

string = raw_input().split(" ")
print "-".join(string)

'''


''' find a string
string = raw_input()
substring = raw_input()

sublen = len(substring)
count = 0
for i in range(0,len(string)-sublen+1):
    if string[i:sublen+i] == substring:
         count += 1

print count
'''



























