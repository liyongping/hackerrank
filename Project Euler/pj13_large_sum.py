'''
we also could conside use double to save accurate previous 10 digit.

'''

numbers = []
for x in range(0,input()):
    numbers.append(int(raw_input()))
sum_str = str(sum(numbers))
print int(sum_str[0:10])