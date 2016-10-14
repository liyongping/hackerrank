#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k. 
 */
class Solution {
public:
    /*
    使用map数据结构来解,用来记录数字和其下标之间的映射。 
    这里需要两个指针i和j，刚开始i和j都指向0，然后i开始向右走遍历数组，
    如果i和j之差大于k，且map中有nums[j]，则删除并j加一。这样保证了m中所有的数的下标之差都不大于k，
    然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方，
    所有小于这个阈值的数和nums[i]的差的绝对值会大于t (可自行带数检验)。
    然后检测后面的所有的数字，如果数的差的绝对值小于等于t，则返回true。最后遍历完整个数组返回false
     */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // maintain window whose size is <= k
            if (i - j > k && m[nums[j]] == j) {
                m.erase(nums[j++]);
            }
            auto a = m.lower_bound(nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) 
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> data2{ 1,23,58,111,22,125, 20 };
    s.containsNearbyAlmostDuplicate(data2, 1, 3);
    return 0;
}