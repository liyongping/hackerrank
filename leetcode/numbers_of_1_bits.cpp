#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define uint32_t unsigned int
/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */
class Solution {
public:
    int hammingWeight1(uint32_t n) {
        int count = 0;
        while(n){
            // get the last bit
            int x = n & 0x1;

            count += x;
            // remove the last bit, get new value
            n = n >> 1;
        }
        return count;
    }

    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            /*
            Expression  Value
            X           0 1 0 0 0 1 0 0 0 1 0 0 0 0
            X-1         0 1 0 0 0 1 0 0 0 0 1 1 1 1
            X & (X-1)   0 1 0 0 0 1 0 0 0 0 0 0 0 0

            Use above rule to remove a '1' every times.
             */
            n = n & (n-1);
            count ++ ;
        }

        return count;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    cout<< "10:" << s.hammingWeight1(10) << endl;
    cout<< "8:" << s.hammingWeight1(8) << endl;
    cout<< "7:" << s.hammingWeight1(7) << endl;

    cout<< "10:" << s.hammingWeight(10) << endl;
    cout<< "8:" << s.hammingWeight(8) << endl;
    cout<< "7:" << s.hammingWeight(7) << endl;
    /* code */
    return 0;
}