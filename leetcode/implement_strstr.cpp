#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack. 

a. brute force
b. KMP http://www.tuicool.com/articles/VrYVJb
 */

class Solution {
public:
    int strStr0(string haystack, string needle) {
        int i = 0, j = 0;
        for (i= j = 0; i < haystack.size() && j < needle.size(); )
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }else{
                i = i-j+1;
                j = 0;
            }
        }

        return j != needle.size() ? -1: i-j;
        
    }

    /* brute force */
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        for (i= j = 0; i < haystack.size() && j < needle.size(); )
        {
            if (haystack[i++] == needle[j++]) {
                i = i-j+1;
                j = 0;
            }
        }

        return j != needle.size() ? -1: i-j;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<< s.strStr("abcdefg","cd") << endl;
    cout<< s.strStr("","") << endl;
    cout<< s.strStr("ababababc","abc") << endl;
    return 0;
}