#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
 */
class Solution {
public:
    /*
    考虑全部用二进制表示，如果我们把 第 ith  个位置上所有数字的和对3取余，
    那么只会有两个结果 0 或 1 (根据题意，3个0或3个1相加余数都为0). 
    因此取余的结果就是那个 “Single Number”.
     */
    int singleNumber(vector<int>& nums) {
        int bitCount[32] = {0};
        int length = nums.size();
        int result = 0;

        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < length; ++j)
            {
                if((nums[j]>>i) & 0x1)
                    bitCount[i]++;
            }

            result |= ((bitCount[i] % 3) << i);
        }

        return result;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(10000);

    cout<<s.singleNumber(nums)<< endl;
    /* code */
    return 0;
}