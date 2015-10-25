#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int is_pangram(char *string, int length)
{
    int char_counts[26] = {0};
    int char_index = 0;

    int i=0;
    for (i = 0; i < length; ++i)
    {
        
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            char_index = tolower(string[i])-'a';
            //printf("%c,%d\n", tolower(string[i]),char_index);
            char_counts[char_index] = 1;// found one
        }
    }

    for (i = 0; i < 26; ++i)
    {
        if(char_counts[i] != 1)
            return 0;
    }
    return 1;
}

int main() {

    int n=0, i=0, cycle=0;
    char string[10000] = {0};
    //getline(string,sizeof(string),stdin);
    
    // read a line for static allocation
    scanf("%[^\n]", string);

    //printf("%s\n", string);
    if (is_pangram(string,strlen(string)))
    {
        printf("pangram\n");
    }
    else
    {
        printf("not pangram\n");
    }
    return 0;
}