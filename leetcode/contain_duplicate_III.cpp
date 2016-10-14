/*
Given an array of integers, 
find out whether there are two distinct indices i and j 
in the array such that the difference between nums[i] 
and nums[j] is at most t and the difference between i and j is at most k. 
 */


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int,int> maps;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(maps.find(nums[i]) != maps.end() 
                && i-maps[nums[i]] <=k
                && abs(nums[i]- nums[maps[nums[i]]]) <=t)
                return true;
            else
                maps[nums[i]] = i;
        }

        return false;
    }
};