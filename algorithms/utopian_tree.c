#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calc_high(int cycle) {
    if(cycle == 0)
        return 1
    if(cycle%2 == 0 && cycle > 1)
        return calc_high(cycle-1)+1
    else
        return calc_high(cycle-1)*2
}

int main() {
    int n=0, i=0, cycle=0;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&cycle);
        printf("%d\n", calc_high(cycle));
    }   
    return 0;
}