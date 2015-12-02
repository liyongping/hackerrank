#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        
        int length = nums.size();
        
        for(int i=0; i< length; i++){
            // usually, i^nums[i] should be 0, if the array is ordered, and there isn't missing number.
            result = result^ i ^ nums[i];
        }
        return result^length;
    }

    int missingNumber1(vector<int>& nums) {
        int result = 0;
        
        int n = nums.size();
        
        for(int i=0; i< n; i++){
            result += nums[i];
        }
        return n*(n+1)/2-result;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);

    cout<<s.missingNumber(nums)<< endl;
    /* code */
    return 0;
}