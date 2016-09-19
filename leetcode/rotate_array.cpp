#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printVectorInt(vector<int> & vs);

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, 
the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 

refer to: https://discuss.leetcode.com/topic/9801/summary-of-c-solutions/8
 */
class Solution {
public:
	/* easy understand, but time limit exceeded*/
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < 2)
        	return;
        int realk = k % size;
        // move one, every time
        for(int i=0; i<realk; i++){
        	int lastV = nums[size-1];
        	for(int j=size-1; j>0; j--){
        		nums[j] = nums[j-1];
        	}
        	nums[0] = lastV;
        }

    }
};

int main(int argc, char const *argv[])
{
    int test[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> nums(test,&test[9]);
    //std::copy(nums.begin(), &test[0], &test[10]);
    printVectorInt(nums);

    Solution s;
    s.rotate(nums, 2);

    printVectorInt(nums);
    return 0;
}


void printVectorInt(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << " ";
    }
    cout<< endl;
}