#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printVectorInt(vector<int> & vs);

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if(nums.size() < 3)
            return results;
        sort(nums.begin(), nums.end());
        
        const int target = 0;
        auto last = nums.end();
        for(auto curr=nums.begin(); curr<last-2; curr++){
            // skip the same element
            if(*curr ==*(curr-1) && curr> nums.begin())
                continue;

            auto front = curr+1;
            auto back = last-1;
            while(front<back){
                if(*curr+*front+*back < target){
                    front++;
                    //skip same elements
                    while(*front==*(front-1) && front<back)
                        front++;
                }
                else if(*curr+*front+*back > target){
                    back--;
                    //skip same elements
                    while(*back==*(back+1) && front<back)
                        back--;
                }else{
                    results.push_back({*curr,*front,*back});
                    front++;
                    back--;
                    //skip same elements
                    while(*front==*(front-1) && front<back)
                        front++;
                    //skip same elements
                    while(*back==*(back+1) && front<back)
                        back--;
                }
            }
       }
       return results;
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