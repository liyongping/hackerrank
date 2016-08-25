#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede". 
 */

class Solution {
public:
    string reverseVowels(string s) {
        int size = s.length();
        int start=0, end=size-1;
        string vowels = "aeiouAEIOU";

        while(start<end){

            while( start<end && vowels.find(s[start])==string::npos )
                start++;
            while( start<end && vowels.find(s[end])==string::npos )
                end--;

            if(start < end)
                swap(s[start++], s[end--]);
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverseVowels("hello");
    return 0;
}