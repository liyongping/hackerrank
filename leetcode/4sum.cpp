#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printVectorInt(vector<int> & vs);

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]


 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        const int size = nums.size();
        unordered_multimap<int, pair<int, int>> cache_2sum;
        for (auto i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size -1; ++j)
            {
                cache_2sum.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));

            }
        }

        for (auto curr = cache_2sum.begin(); curr != cache_2sum.end(); curr++) {
            int curr_sum = curr->first;
            auto it_bounds = cache_2sum.equal_range(target - curr_sum);
            for (auto it = it_bounds.first; it != it_bounds.second; it++) {
                auto a = curr->second.first;
                auto b = curr->second.second;
                auto c = it->second.first;
                auto d = it->second.second;
                if (a != c && a != d && b != c && b != d) {
                    vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
                    std::sort(vec.begin(), vec.end());
                    results.push_back(vec);
                }
            }
        }

        return results;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> data{1,0,-1,0,-2,2};
    Solution s;
    vector<vector<int>> r = s.fourSum(data,0);
    return 0;
}


void printVectorInt(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << " ";
    }
    cout<< endl;
}