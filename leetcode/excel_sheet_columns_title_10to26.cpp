#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A       x = 1 * pow(26,0)
    2 -> B
    3 -> C
    ...
    26 -> Z       
    27 -> AA     x = 'A' * pow(26,1) + 'A' * pow(26,0)
    28 -> AB     x = 'A' * pow(26,1) + 'B' * pow(26,0)
 */

/* 10 to 26 */
string convertToTitle(int n) {
    string result = "";
    while(n != 0){
    	// get last character
    	char one = (n-1)%26+ 'A';
    	// put it before original result
    	result = one + result;
    	// remove the remainder
    	n = (n-1)/26;
	}
	return result;
}

int main(int argc, char const *argv[])
{
    cout<<convertToTitle(1)<<endl;
    cout<<convertToTitle(26)<<endl;
    cout<<convertToTitle(27)<<endl;
    cout<<convertToTitle(999900)<<endl;
    return 0;
}