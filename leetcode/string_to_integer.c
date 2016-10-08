#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int myAtoi(char* str) {
    long result = 0;
    int negative = 1;
    int currentValue = 0;
    
    int max = 0x7fffffff;  
    int min = 0x80000000;
        
    char *pchar = str;
    if(str == NULL || *str == '\0')
        return 0;
        
    while(*pchar == ' ')
        pchar++;
    
    
    if(*pchar == '-'){
        negative = -1;
        pchar ++;
    }else if(*pchar == '+'){
        negative = 1;
        pchar ++;
    }
    
    
    do{
        if(*pchar <= '9' && *pchar >= '0'){
            result = result*10 + negative*(*pchar - '0');
        }
        else{
            return result;
        }
        
        if(result> max || result < min){
            return result > 0 ? max:min;
        }
    }
    while(*(pchar++) != '\0');
    
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", myAtoi("fefef"));
    printf("%d\n", myAtoi("-1fefef"));
    printf("%d\n", myAtoi("-153r23r23r2"));
    printf("%d\n", myAtoi("153r23r23r2"));
    return 0;
}