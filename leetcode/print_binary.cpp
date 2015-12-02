#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

/*
solution 1: just support unsinged int, don't support nagetive integer.
 */
string print_binary1(unsigned int number){
    string result = "";

    while(number){
        if(number & 0x1){
            result = '1' + result;
        }else{
            result = '0' + result;
        }
        number = number >> 1;
    }

    return result;
}

/*
soultion 2
 */
string print_binary(int number){
    string result = "";

    for (int i = 0; i < 32; ++i)
    {
        if((number>>i) & 0x1){
            result = '1' + result;
        }else{
            result = '0' + result;
        }
    }

    return result;
}


int main(int argc, char const *argv[])
{
    //00000000000000000000000000001010
    cout<< print_binary(10) << endl;
    //11111111111111111111111111110110,负数为原码的补码，计算机中用补码表示负数
    cout<< print_binary(-10) << endl;

    cout<< print_binary(5) << endl; // 00000000000000000000000000000101
    cout<< print_binary(-5) << endl;// 11111111111111111111111111111011

    /*
    Solution 3: use bitset.
     */
    bitset<16> bs(10);
    cout<< bs.to_string() << endl; // 0000000000001010
    cout<< bitset<16>(10) << endl; // 0000000000001010
    cout<< bitset<16>(-10) << endl;// 1111111111110110
    
    return 0;
}