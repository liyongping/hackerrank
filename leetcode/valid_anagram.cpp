class Solution {
public:
    // sort it, and compare the strings
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
    
    // count the number of character, and 
    bool isAnagram(string s, string t) {
        int alf[26] = {0};
        
        for(int i=0; i< s.size(); i++){
            alf[s[i]-'a']++;
        }
        
        for(int i=0; i< t.size(); i++){
            alf[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; i ++)
            if(alf[i] != 0)
                return false;
        return true;
    }
};