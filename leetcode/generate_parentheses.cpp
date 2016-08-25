#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Subscribe to see which companies asked this question

 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        generate(results, "", n, 0);
        return results;
    }

    void generate(vector<string> & vs, string str, int left, int right) {
        if(left ==0 && right == 0) {
            vs.push_back(str);
            return;
        }
        if(left > 0)
            generate(vs, str+"(", left-1, right+1);
        if(right > 0)
            generate(vs, str+")", left, right-1);
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
    vector<string> results = s.generateParenthesis(3);
    printVectorString(results);

    return 0;
}