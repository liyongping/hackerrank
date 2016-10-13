class Solution {

public:

    int addDigits(int num) {
     //return solution1(num); 
     //return solution2(num); 
     return solution3(num);
    }

private:
    /*
    solution 1 and 2 are trying to get remainder because digital root of 10 or dr(10)=9 and 10 % 9=1, dr(11)=2 and 11%9=2, 12%9=3 and so on. The tricky thing is 9%9=0 but we need 9. So I used (9-1)%9 + 1 = 8 + 1 =9 in to make it right.

    Solution3 is the regular method we all came out with.
     */
    int solution1(int num){
        return (num - 1) % 9 + 1;
    }
    int solution2(int num){
        return num - 9 * ((num - 1)/9);
    }
    int solution3(int num){
        if(num < 10) return num;
        return solution3(num / 10 + num % 10);
    }

};