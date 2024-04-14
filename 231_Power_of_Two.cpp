#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    // if(n==0) return false;
    // while(n){
    //     if(n==1) return true;
    //     if(n%2 != 0){
    //         return false;
    //     }
    //     n/=2;
    // }
    // return true;

    // using bit manipulation
        // 16 = 10000
        // 15 = 01111
        //  & = 00000
    if(n<=0) return false; 
    return ((n&(n-1)) ==0);
}


int main()
{
    cout<<isPowerOfTwo(1024)<<endl;
    return 0;
}