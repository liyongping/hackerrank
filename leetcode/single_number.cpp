#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        int length = nums.size();
        // using rule: A ^ B ^ B = A ^ 0 = A
        for(int i=1; i< length; i++){
            result ^= nums[i];
        }
        
        return result;
    }
};


int main(int argc, char const *argv[])
{
	vector<int> test;
	test.push_back(1);
	test.push_back(1);
	test.push_back(2);

	Solution s;

	cout<< s.singleNumber(test) << endl;
	/* code */
	return 0;
}