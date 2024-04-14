#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    vector<int> dp(n+1,0);
    
    if(n==0) return 0;
    if(n==1) return 1;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int m = 10;
    int n = fib(m);

    cout<<"Fibonacci "<<m<<": "<<n<<endl;
    return 0;
}