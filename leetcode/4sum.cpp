#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
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
    //240
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        const int size = nums.size();
        //sort(nums.begin(), nums.end());

        unordered_multimap<int, pair<int, int>> cache_2sum;
        for (auto i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; ++j)
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
                    if (std::find(results.begin(), results.end(), vec) == results.end())
                        results.push_back(vec);
                }
            }
        }

        //sort(results.begin(), results.end());
        //results.erase(unique(results.begin(), results.end()), results.end());

        return results;
    }
    
    //56
    vector<vector<int> > fourSum1(vector<int> &num, int target) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int nSize = num.size();  
        vector< vector<int> > result;  
        if (nSize < 4) return result;  
          
        sort(num.begin(), num.end());  
        vector<int> mid(4);  
        set<string> isExit;  
        for (int i = 0; i < nSize - 3; ++i)  
        {  
            mid[0] = num[i];  
            for (int j = i + 1; j < nSize - 2; ++j)  
            {  
                mid[1] = num[j];  
                int l = j + 1;  
                int r = nSize - 1;  
                int sum = target - num[i] - num[j];  
                while(l < r)  
                {  
                    int tmp = num[l] + num[r];  
                    if (sum == tmp)  
                    {  
                        string str;  
                        str += num[i];  
                        str += num[j];  
                        str += num[l];  
                        str += num[r];  
                        set<string>::iterator itr = isExit.find(str);  
                        if (itr == isExit.end())  
                        {  
                            isExit.insert(str);  
                            mid[2] = num[l];  
                            mid[3] = num[r];  
                            result.push_back(mid);  
                        }  
                        ++l;  
                        --r;  
                    }  
                    else if(sum > tmp)  
                        ++l;  
                    else  
                        --r;  
                }  
            }  
        }  
  
        return result;  
    }  
    
    //96ms
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for (auto a = nums.begin(); a < prev(last, 3); ++a) {
        for (auto b = next(a); b < prev(last, 2); ++b) {
        auto c = next(b);
        auto d = prev(last);
        while (c < d) {
        if (*a + *b + *c + *d < target) {
        ++c;
        } else if (*a + *b + *c + *d > target) {
        --d;
        } else {
        result.push_back({ *a, *b, *c, *d });
        ++c;
        --d;
        }
        }
        }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
    
    //9ms
    vector<vector<int>> fourSum9(vector<int>& nums, int target) 
    {
        vector<vector<int>> lRetVal;
        vector<int> lQuad( 4, 0 ); // Pre-allocate the size of the result

        // Sort to provide a mechanism for avoiding duplicates
        sort( nums.begin(), nums.end() );
        
        KSum( 4, nums, 0, nums.size()-1, target, lRetVal, lQuad, 0 );

        return( lRetVal );        
    }
    
    // Valid for K >= 2
    void KSum(int k, 
        vector<int>& nums, 
        int l, 
        int r, 
        int target, 
        vector<vector<int>>& retVal, 
        vector<int>& cur, 
        int ci ) 
    {
        int i, mn, mx;
        int km1 = k - 1;

        // invaid input
        if ( r-l+1 < k ) return;
        
        while ( l < r )
        {
            mn = nums[l];
            mx = nums[r];
            
            // If K minus 1 largest + min < target, move to larger
            if ( ( mn + km1*mx ) < target ) l++;
            // If K minus 1 smaller + max > target, move to smaller
            else if ( ( km1*mn + mx ) > target ) r--;
            // If K * min > target, stop looking
            else if ( k*mn > target ) break;
            // If K * min == target, reached the threshold, check then stop looking
            else if ( k*mn == target )
            {
                if ( ( l + km1 <= r ) && ( mn == ( nums[l+km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) cur[ci+i] = mn;
                    retVal.push_back( cur );
                }
                break;
            }
            // If K * max < target, stop looking
            else if ( k*mx < target ) break;
            // If K * max == target, reached the threshold, check then stop looking
            else if ( k*mx == target )
            {
                if ( ( l <= r - km1 ) && ( mx == ( nums[r-km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) cur[ci+i] = mx;
                    retVal.push_back( cur );
                }
                break;                
            }
            // If K == 2, we found a match!
            else if ( k == 2 )
            {
                cur[ci] = mn;
                cur[ci+1] = mx;
                retVal.push_back( cur );
                l++;
                while ( ( l < r ) && ( nums[l] == mn ) ) l++;
                r--;
                while ( ( l < r ) && ( nums[r] == mx ) ) r--;
            }
            // Otherwise, convert the problem to a K-1 problem
            else
            {
                cur[ci] = mn;
                KSum( km1, nums, ++l, r, target - mn, retVal, cur, ci+1 );
                while ( ( l < r ) && ( nums[l] == nums[l-1] ) ) l++;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> data;
    for (int i = -40; i < 40; ++i)
    {
        data.push_back(i);
    }
    Solution s;
    vector<vector<int>> r = s.fourSum(data,0);
    cout<< r.size() << endl;
    return 0;
}


void printVectorInt(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << " ";
    }
    cout<< endl;
}