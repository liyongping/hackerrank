#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int alter_char(char *string, int length)
{
    int i=0,count=0;
    for (i = 0; i < length-1; ++i)
    {
        if(abs(string[i]-string[i+1]) == 0)
        {
            count++;
        }
    }
    return count;
}

int main() {

    int n=0, i=0, cycle=0;
    char string[100000] = {0};
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        memset(string,0,sizeof(string));
        scanf("%s",string);

        printf("%d\n",alter_char(string,strlen(string)));
    }

    return 0;
}