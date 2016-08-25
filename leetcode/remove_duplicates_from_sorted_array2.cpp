#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, 
with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length. 
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(index < 2 || nums[i] != nums[index-2])
                nums[index++] = nums[i];
        }
        return index;
    }

    int removeDuplicates2(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); ++i)
        {
            if(nums[i] != nums[index-2])
                nums[index++] = nums[i];
        }
        return index;
    }

    /*
    https://leetcode.com/discuss/22584/share-time-and-solution-when-duplicates-allowed-most-times
     */
    int removeDuplicatesN(int A[], int n, int k) {

            if (n <= k) return n;

            int i = 1, j = 1;
            int cnt = 1;
            while (j < n) {
                if (A[j] != A[j-1]) {
                    cnt = 1;
                    A[i++] = A[j];
                }
                else {
                    if (cnt < k) {
                        A[i++] = A[j];
                        cnt++;
                    }
                }
                ++j;
            }
            return i;
    }
};

void printVectorInt(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << " ";
    }
    cout<< endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int array[9] = {1,1,1,2,2,3,3,3,4};
    vector<int> nums(array,array+9);
    printVectorInt(nums);

    cout<< s.removeDuplicates(nums) <<endl;

    printVectorInt(nums);
    return 0;
}