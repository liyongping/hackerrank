#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings. 
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            if(strs[i].length()==0 || prefix.length()==0)
                return "";
            //取较小长度
            int maxlen = prefix.length() < strs[i].length() ? prefix.length() : strs[i].length();
            int j = 0;
            for (j = 0; j < maxlen; ++j)
            {
                if(prefix[j] != strs[i][j])
                    break;
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }

    string longestCommonPrefix2(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        string prefix = "";
        int y = 0;

        for (int x = 0; x < strs[0].size(); ++x)
        {
            //当所有字符串的这一列的字符相同的时候，保存下来
            for (y = 1; y < strs.size(); ++y)
            {
                if(strs[y][x] != strs[0][x])
                    return prefix;
            }
            prefix += strs[0][x];

        }
        return prefix;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<string> strs;
    strs.push_back("abctttt");
    strs.push_back("a");
    strs.push_back("abctttt");
    strs.push_back("abctttt");
    strs.push_back("abctttt");

    cout << s.longestCommonPrefix2  (strs) << endl;
    return 0;
}