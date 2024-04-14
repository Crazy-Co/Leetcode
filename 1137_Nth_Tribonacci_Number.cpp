#include<bits/stdc++.h>
using namespace std;

 int tribMem(int n, vector<int> &dp){
    // base case
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;

    // check if dp[n] is already calculated
    if(dp[n] != -1) return dp[n];

    dp[n] = tribMem(n-1, dp) + tribMem(n-2, dp) + tribMem(n-3, dp);
    return dp[n];
}

int tribTab(int n){
    vector<int> dp(n+1,0);

    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;

    // base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int tribonacci(int n) {
    // vector<int> dp(n+1, -1);
    // return tribMem(n, dp);

    return tribTab(n);
}


int main(){
    int m = 10;
    int n = tribonacci(m);
    cout<<"Tribonacci "<<m<<": "<<n<<endl;
    return 0;
}