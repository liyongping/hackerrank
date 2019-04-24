
class Solution {
    public: int divide(int dividend, int divisor) { //处理溢出情况 
        if (divisor == 0 || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
        bool is_neg = 0; //处理负数 
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            is_neg = 1;
        }
        int result = 0;
        unsigned int did = __abs(dividend);
        unsigned int dir = __abs(divisor); //减少减法的次数 
        while (did >= dir) {
            long temp = dir;
            long mul = 1; //找出除数倍数最大的数，但是小于被除数 
            while (did >= temp << 1) {
                temp = temp << 1;
                mul = mul << 1;
            }
            did -= temp;
            result += mul;
        }
        return is_neg ? -result : result;
    } //绝对值函数 
    unsigned int __abs(int value) {
        unsigned int copyed_value = value;
        return (copyed_value > 0x80000000) ? -value : copyed_value;
    }
};

