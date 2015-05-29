#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int is_funny(char *string, int length)
{
    int i=1;
    for (i = 1; i < length-1; ++i)
    {
        if(abs(string[i]-string[i-1]) != abs(string[length-1-i]-string[length-i]))
        {
            return 0;
        }
    }
    return 1;
}

int main() {

    int n=0, i=0, cycle=0;
    char string[10000] = {0};
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        memset(string,0,sizeof(string));
        scanf("%s",string);
        if (is_funny(string,strlen(string)))
        {
            printf("Funny\n");
        }
        else
        {
            printf("Not Funny\n");
        }
    }

    return 0;
}
