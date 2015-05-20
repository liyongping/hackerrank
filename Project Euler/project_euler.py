''' Project Euler #1: Multiples of 3 and 5
#v1:
for i in range(0, input()):
    sum = 0
    for n in range(0, input()):
        if (n % 5 == 0 or n % 3 == 0):
            sum += n
    print sum

    
for i in range(0, input()):
    sum = 0
    j = 0;
    tmp = input()
    j = (tmp-1)/3;
    sum = 3*(j*(j+1)/2);
    j = (tmp-1)/5;
    sum = sum + 5*(j*(j+1)/2);
    j = (tmp-1)/15;
    sum = sum - 15*(j*(j+1)/2);
    print sum

'''
