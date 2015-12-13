#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

/*
 Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number. 
 */

class Solution {
public:
    /*
    
     */
    bool isUgly(int num) {
        // note: num == 0
        if(num <= 0)
            return false;

        while(num % 2 == 0) num = num >> 1;// num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;

        return num == 1;
    }
};


int main(int argc, char const *argv[])
{

    Solution s;
    cout<<s.isUgly(1001)<<endl;
    cout<<s.isUgly(1)<<endl;
    cout<<s.isUgly(10)<<endl;
    return 0;
}