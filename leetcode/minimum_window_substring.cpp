#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        // 尾指针i不断往后扫描
        for (int i = 0; i < s.size(); ++i) {
            //如果减1后的映射值仍大于等于0，说明当前遍历到的字母是T串中的字母，我们使用一个计数器 cnt，使其自增1
            ////对于不在T串中的字母的映射值也会减少，其实没啥事，因为对于不在T串中的字母，我们减1后，变-1，cnt不会增加，之后收缩左边界的时候，映射值加1后为0，cnt也不会减少，所以并没有什么影响啦
            if (--letterCnt[s[i]] >= 0) ++cnt;
            //当 cnt 和T串字母个数相等时，说明此时的窗口已经包含了T串中的所有字母
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                /* 开始收缩左边界，由于我们遍历的时候，对映射值减了1，所以此时去除字母的时候，就要把减去的1加回来，
                此时如果加1后的值大于0了，说明此时我们少了一个T中的字母，那么 cnt 值就要减1了，然后移动左边界 left
                */
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout<< s.minWindow("AABC", "ABC");
    
    return 0;
}