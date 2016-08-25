#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;
/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 
 */

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

class Solution {
public:
    string countAndSay(int n) {
        int i = 1;
        string ret = "1";
        while(i++ < n) {
            ret = revolution(ret);
        }
        return ret;
    }
    /*
    根据输入的字符串，计算下一个字符串
     */
    string revolution(string input) {
        int len = input.length();
        int count = 1;
        string cur = "";
        for (int i = 0; i < len; ++i)
        {
            count = 1;
            while(i < len-1 && input[i] == input[i+1]){
                count++;
                i++;
            }
            cur += to_string(count)+input[i];
        }
        return cur;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << argv[1] << endl;
    cout<< s.countAndSay(atoi(argv[1])) <<endl;
    return 0;
}