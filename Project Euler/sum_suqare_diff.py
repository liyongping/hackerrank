
sum1 = 0;
for x in range(1,101):
    sum1 += pow(x,2)

print sum1;
sum2 =  pow(sum(range(1,101)),2)
print sum2 - sum1