#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail = s.length() -1;
        int length = 0;
        //从尾部开始计算，首先移除尾部的空格
        while(tail >=0 && s[tail] == ' ')
            tail--;
        while(tail >=0 && s[tail--] != ' ')
            length++;
        return length;
    }

    int lengthOfLastWord2(string s) {
        int cnt = 0, i = 0;
        int length = s.length()-1;
        while(i <= length) {
            //当前字符为空的话，如果下一个字符不为空，把cnt重置为0
            if(s[i++] != ' ')
                cnt++;
            else if(i < length && s[i] != ' ')
                cnt = 0;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.lengthOfLastWord2(" Hello world ") << endl;
    return 0;
}