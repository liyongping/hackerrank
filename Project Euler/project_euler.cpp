#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long n = 0, sum =0, tmp =0,j=0;
    scanf("%ld",&n);
    for(int i=0; i<n; i++)
    {
        sum = 0;
        scanf("%d",&tmp);
        j = (tmp-1)/3;
        sum = 3*(j*(j+1)/2);
        j = (tmp-1)/5;
        sum = sum + 5*(j*(j+1)/2);
        j = (tmp-1)/15;
        sum = sum - 15*(j*(j+1)/2);
        printf("%ld\n",sum);
    }
    
    return 0;
}