class Solution {
public:
    int titleToNumber(string s) {
        long result = 0;
        for(int i=0; i<s.size(); i++){
            result = (s[i]-'A'+1) + result*26;
        }
        return result;
    }
};