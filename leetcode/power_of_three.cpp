/*
 Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion? 

 */
bool isPowerOfThree0(int n) {
    while(n>0 && n%3 ==0){
        n = n/3;
    }
    
    return n==1;
}

/*
log 3 n = log 10 n / log 10 3
在c++中判断数字a是否为整数，我们可以用 a - int(a) == 0 来判断
*/
bool isPowerOfThree(int n) {
    return n > 0 && (int)(log10(n) / log10(3)) - log10(n) / log10(3) == 0;
}