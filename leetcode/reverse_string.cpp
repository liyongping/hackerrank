#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int j = s.length()-1, i=0;
        /*
        for (i = 0; i < j; ++i)
        {
            char swap = s[i];
            s[i] = s[j];
            s[j] = swap;
            j--;
        }
        */
        while(i<j) {
            swap(s[i++],s[j--]);
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverseString("test") << endl;
    cout << s.reverseString("t") << endl;
    cout << s.reverseString("") << endl;
    return 0;
}