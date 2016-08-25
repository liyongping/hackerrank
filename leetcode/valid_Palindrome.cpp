#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size()-1;
        while(begin < end) {
            while(!isValid(s[begin]) && begin<end)
                begin++;
            while(!isValid(s[end]) && begin<end)
                end--;
            if(tolower(s[begin++]) != tolower(s[end--]))
                return false;
        }
        return true;
    }

    bool isValid(char c) {
        if(c>='0' && c<='9')
            return true;
        if(c>='a' && c<='z')
            return true;
        if(c>='A' && c<='Z')
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<< s.isPalindrome("A man, a plan, a canal: Panama") <<endl;
    return 0;
}