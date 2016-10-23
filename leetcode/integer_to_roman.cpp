/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"};

        string roman = "";
        int i = 0;
        while(num > 0){
        	// get the highest number
        	int count = num/radix[i];
        	if(count > 0){
        		while(count-- > 0)
        			roman += symbol[i];
        	}
        	// get the raminder
        	num = num % radix[i];
        	i++;
        }

        return roman;
    }
};