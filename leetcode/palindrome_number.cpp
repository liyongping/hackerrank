/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        	return false;
        // get base, e.g. the base for 12321 is 10000.
        int base = 1;
        while(x/base >= 10){
        	base *= 10;
        }

        while(x>0){
        	// get highest element
        	int q = x/base; // quotient
        	// get lowest element
        	int r = x%10;   // raminder
        	if(q != r)
        		return false;
        	// 12321%10000 = 2321/10 = 232
        	x = x%base / 10;
        	// we have removed 2 elements, so need to /100.
        	base /= 100;
        }

        return true;
    }
};