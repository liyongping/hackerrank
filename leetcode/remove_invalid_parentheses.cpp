#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Remove the minimum number of invalid parentheses in order to make the input string valid. 
 Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

 */
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
    }
};

void printVectorString(vector<string> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> results = s.removeInvalidParentheses(3);
    printVectorString(results);

    return 0;
}