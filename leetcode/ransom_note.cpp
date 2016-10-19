/*
  Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[256] = {0};

        //use table to record the times
        for (int i = 0; i < magazine.size(); ++i)
        {
            table[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); ++i)
        {
            if(table[ransomNote[i]] > 0)
                table[ransomNote[i]]--;
            else
                return false;
        }
        return true;
    }
};