#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0;
        int length = nums.size();

        for (int i = 0; i < length; ++i)
        {
            if(nums[i] != val){
                //使用后面的有效元素，覆盖要移除的元素
                nums[begin++] = nums[i];
            }
        }

        return begin;
    }

    int removeElement2(vector<int>& nums, int val) {
        int begin = 0;
        int length = nums.size();

        while(begin <length) {
            if(nums[begin] == val){
                //把后面的元素换到前面来，覆盖要移除的元素
                nums[begin] = nums[length-1];
                length--;
            }else{
                begin++;
            }
        }
        return begin;
    }
};

void printVectorString(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums;
    for (int i = 1; i < 11; ++i)
    {
        nums.push_back(i);
    }

    nums.push_back(3);

    cout<< s.removeElement2(nums, 3) << endl;
    printVectorString(nums);

    return 0;
}