#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

 */

class Solution {
public:
    // Runtime: O(n), space: O(n)
    int majorityElement1(vector<int>& nums) {
        map<int,int> counts;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if(counts.find(nums[i]) == counts.end()){
                counts[nums[i]] = 1;
            }else{
                counts[nums[i]] ++;
            }

            if(counts[nums[i]] > length/2){
                return nums[i];
            }
        }
        return 0;
    }

    //Moore’s Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }else{
                candidate == nums[i] ? count++ : count--;
            }
        }
        return candidate;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(1);

    Solution s;
    cout<<s.majorityElement(nums)<<endl;
    cout<<s.majorityElement1(nums)<<endl;
    return 0;
}