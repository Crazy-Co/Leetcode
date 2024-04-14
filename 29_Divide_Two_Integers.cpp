class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        else if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        int q=0;
        int sign=1;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
        
        long int dividend_abs = abs(dividend), divisor_abs = abs(divisor);
        if(divisor_abs == 1 ) return dividend_abs * sign;

        while(dividend_abs>=divisor_abs){
            dividend_abs-=divisor_abs;
            q++;
        }
        return q*sign;
    }
};