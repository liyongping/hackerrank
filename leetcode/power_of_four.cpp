/*
 Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion? 

 */

bool isPowerOfFour0(int num) {
    while(num > 0 && num%4 == 0){
        num/=4;
    }
    return num==1;
}

bool isPowerOfFour2(int num) {
    return num>0 && (int)(log10(num)/log10(4)) - log10(num)/log10(4) == 0;
}

/* 确定其是2的次方数了之后，发现只要是4的次方数，减1之后可以被3整除 */
bool isPowerOfFour(int num) {
    return num>0 && ((num & (num-1)) == 0) && (num-1)%3==0;
}