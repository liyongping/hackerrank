class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int length = nums.size();
        
        if(length > 1){
            for(int i=1; i< length; i++){
                if(nums[i-1] == nums[i])
                    return true;
            }
        }
        
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        int length = nums.size();
        map<int,int> maps;
        for(int i=0; i< length; i++){
            // find it
            if(maps.find(nums[i]) != maps.end()){
                return true;
            }else{
                maps[nums[i]] = 1;
            }
        }
        
        return false;
    }
};