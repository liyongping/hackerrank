/*
Implement pow(x, n). 
 */
// 分治法
double mypower(double x, int n){
    double halfpower = 0;
    if(n == 0)
        return 1;
    
    halfpower = mypower(x, n/2);
    
    if(n%2==0)
        return halfpower * halfpower;
    else
        return halfpower * halfpower * x;
}



double myPow(double x, int n) {
    if(n < 0){
        return 1/mypower(x, -n);
    }else{
        return mypower(x, n);
    }
}