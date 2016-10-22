/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

 */
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        string rs = "";
        int j = n;
        // backwards
        for (int i = n-1; i >= 0; i--)
        {
            if (s[i] == ' ') {
                j = i;
            }
            // i=0 must be put befor s[i - 1] == ' ' to prevent s[i-1] error
            else if(i == 0 || s[i - 1] == ' '){
                if (rs.size() != 0) {
                    rs += " ";
                }
                rs += s.substr(i, j-i);
            }
        }
        s = rs;
    }
};