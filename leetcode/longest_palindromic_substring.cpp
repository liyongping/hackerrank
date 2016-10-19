/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
 */

class Solution {
public:
    /*
    动态转移方程:
    Define P[ i, j ] ← true if the substring Si … Sj is a palindrome, otherwise false.

    P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj ) ，显然，如果一个子串是回文串，并且如果从它的左右两侧分别向外扩展的一位也相等，那么这个子串就可以从左右两侧分别向外扩展一位。

    其中的base case是
    P[ i, i ] ← true
    P[ i, i+1 ] ← ( Si = Si+1 )

     */
    string longestPalindrome(string s) {  
      int n = s.length();  
      int longestBegin = 0;  
      int maxLen = 1;  
      bool table[1000][1000] = {false};

      //P[i][i] must be true
      for (int i = 0; i < n; i++) {  
        table[i][i] = true;  
      }
      //P[i][i+1] is true if s[i]==s[i+1]
      for (int i = 0; i < n-1; i++) {  
        if (s[i] == s[i+1]) {  
          table[i][i+1] = true;  
          longestBegin = i;  
          maxLen = 2;  
        }  
      }

      
      for (int len = 3; len <= n; len++) {  
        for (int i = 0; i < n-len+1; i++) {  
          int j = i+len-1;  
          if (s[i] == s[j] && table[i+1][j-1]) {  
            table[i][j] = true;  
            longestBegin = i;  
            maxLen = len;  
          }  
        }  
      }  
      return s.substr(longestBegin, maxLen);  
    }
};