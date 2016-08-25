#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.size()-1;
        int b_len = b.size()-1;
        string ret = "";
        int c = 0;
        while(a_len>=0 || b_len>=0 || c==1) {
            c += a_len>=0 ? a[a_len--]-'0' : 0;
            c += b_len>=0 ? b[b_len--]-'0' : 0;
            ret = char(c%2+'0') + ret;
            c /= 2; // c = c>>1;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<< s.addBinary("1000", "1") << endl;
    cout<< s.addBinary("1000", "1000") << endl;
    cout<< s.addBinary("1000", "111") << endl;
    return 0;
}