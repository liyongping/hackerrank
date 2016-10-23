/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    int romanToInt(string s) {
        const int radix[] = {1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"};

        int n = s.size();
        int result = 0;
        for(int i = 0; i < n; i++){
        	if(i > 0 && map(s[i]) > map(s[i-1])){
        		/* 如果当前的值 比上一个大，那么当前值=当前值-上一个值.
        		   e.g. IV = 5-1
        		        VI = 6
        		*/
        		// 2*： 因为上一次多加了一次值
        		result += (map(s[i]) - 2*map(s[i-1]));
        	}else{
        		result += map(s[i]);
        	}
        }
        
        return result;
    }

    int map(char r){
    	switch(r){
    		case 'I': return 1;
    		case 'V': return 5;
    		case 'X': return 10;
    		case 'L': return 50;
    		case 'C': return 100;
    		case 'D': return 500;
    		case 'M': return 1000;
    		default:  return 0;
    	}
    }
};