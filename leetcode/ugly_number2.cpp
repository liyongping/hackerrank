#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

/*
 Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

    The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
    An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
    The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
    Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

丑陋数序列可以拆分为下面3个子列表：

(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …

仔细观察上述三个列表，我们可以发现每个子列表都是一个丑陋数乘以2,3,5，
而这些丑陋数的值就是从已经生成的序列中取出来的，
我们每次都从三个列表中取出当前最小的那个加入序列
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> list;

        int i = 0;
        list.push_back(1);
        
        int i2 =0, i3=0, i5=0;
        int m2 =0, m3=0, m5=0;
        while(n > list.size()){
            m2= list[i2]*2;
            m3= list[i3]*3;
            m5= list[i5]*5;

            int m = min(m2,min(m3,m5));
            list.push_back(m);

            if(m == m2) i2++;
            if(m == m3) i3++;
            if(m == m5) i5++; 
        }

        return list.back();
    }
};


int main(int argc, char const *argv[])
{

    Solution s;
    cout<<s.nthUglyNumber(5)<<endl;
    cout<<s.nthUglyNumber(1)<<endl;
    cout<<s.nthUglyNumber(10)<<endl;
    return 0;
}