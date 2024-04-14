class Solution {
public:
    int reverse(int x) {
        if(x==0 || x == INT_MIN) return 0;
        int n=0;
        while(x){
            int digit = x%10;
            if(n > INT_MAX/10 || n < INT_MIN/10)return 0;
            n = n*10 + digit;
            x/=10;
        }
        return n;
    }
};