#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 */
class Solution {
public:
    bool isValid(string s) {
        const char *clist = s.c_str();
        stack<char> paren;
        for (int i = 0; i < s.length(); ++i)
        {
            if(clist[i] == '(' || clist[i] == '{' || clist[i] == '[')
                paren.push(clist[i]);
            else{
                if(paren.empty())
                    return false;
                if(clist[i] == ')' && paren.top() != '(')
                    return false;
                if(clist[i] == ']' && paren.top() != '[')
                    return false;
                if(clist[i] == '}' && paren.top() != '{')
                    return false;
                paren.pop();
            }
        }
        return paren.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<< s.isValid("[]{") << endl;
    cout<< s.isValid("[](){}") << endl;
    return 0;
}