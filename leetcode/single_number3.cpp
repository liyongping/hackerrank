#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //  initialize result with 2 member, every one is 0.
        vector<int> result(2,0);
        
        int length = nums.size();
        
        int twoXOR = 0;
        for(int i=0; i< length; i++){
            twoXOR ^= nums[i];
        }
        // use twoXOR & (-twoXOR) to get the last '1' in twoXOR
        int mask = twoXOR & (-twoXOR);
        //int mask = twoXOR & (~(twoXOR-1));
        for(int i=0; i< length; i++){
            // remember to add () to hold the "nums[i] & mask", the priority of '&' < '=='
            if((nums[i] & mask) == 0){
                result[0] ^= nums[i];
            }else{
                result[1] ^= nums[i];
            }
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    std::vector<int> result = s.singleNumber(nums);
    cout<<result[0]<< endl;
    cout<<result[1]<< endl;
    cout<<result.size()<< endl;
    /* code */
    return 0;
}