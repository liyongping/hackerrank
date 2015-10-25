#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
	char *presult[numRows];
	int i = 0,imod = 0, step_size = 0;

    if(numRows == 1)
    	return s;

    step_size = 2*numRows-2;
    for(i=0; i<numRows; i++)
    {
    	presult[i] = (char *)malloc(sizeof(char) * (strlen(s)+1));
    	memset(presult[i],0,sizeof(char) * (strlen(s)+1));
    }

    for(i=0; i<strlen(s); i++)
    {
    	imod = i%step_size;
    	if(imod < numRows){
    		strncat(presult[imod],s+i,1);
    	}
    	else
    	{
    		strncat(presult[2*(numRows-1)-imod],s+i,1);
    	}
    }

    //for(i=0; i<numRows; i++)
    //{
    //	printf("%s\n",presult[i]);
    //}

    for(i=1; i<numRows; i++)
    {
    	strcat(presult[0],presult[i]);
    	free(presult[i]);
    }

    return presult[0];
}


int main(int argc, char** args)
{
	printf("%d \n", strlen("123"));
	printf("%s\n",convert("ABCDEFGHIJKLMN",1));
	printf("%s\n",convert("ABCDEFGHIJKLMN",2));
	printf("%s\n",convert("ABCDEFGHIJKLMN",3));
	printf("%s\n",convert("ABCDEFGHIJKLMN",5));
	printf("%s\n",convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 3));
	printf("%s\n",convert("ABCDEF",5));
	printf("%s\n",convert("mxnafamespckjcazxdrtdgyrqscczybnvqqcqcjitlvcnvbmasidzgwraatzzwpwmfbfjkncvkelhhzjchpd", 80));
}
