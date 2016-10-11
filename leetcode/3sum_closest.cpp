#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printVectorInt(vector<int> & vs);

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());

        int minimum = INT_MAX, result=0;
        auto last = nums.end();
        for (auto curr = nums.begin(); curr < last-2; ++curr)
        {
            auto front = curr+1;
            auto back = last-1;
            while(front<back){
                // find closer
                int curr_sum = *curr + *front + *back;
                int gap = abs(curr_sum - target);
                if(gap < minimum){
                    minimum = gap;
                    result = curr_sum;
                }

                if(curr_sum < target)
                    front++;
                else
                    back--;

            }
        }
        return result;
    }

    int threeSumClosest2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int minimum = INT_MAX, result=0;
        int size = nums.size();
        for (int curr = 0; curr < size-2; ++curr)
        {
            int front = curr+1;
            int back = size-1;
            while(front<back){
                // find closer
                int curr_sum = nums[curr] + nums[front] + nums[back];
                int gap = abs(curr_sum - target);
                if(gap < minimum){
                    minimum = gap;
                    result = curr_sum;
                }

                if(curr_sum < target)
                    front++;
                else
                    back--;

            }
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


void printVectorInt(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << " ";
    }
    cout<< endl;
}