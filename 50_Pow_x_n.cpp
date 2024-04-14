#include <bits/stdc++.h>
using namespace std;

double pow(double x, int n)
{
    if (n < 0){
        x = 1 / x;
        n = abs(n);
    }
    if (n == 0) return 1;
    if (n == 1) return x;

    double y = pow(x, n / 2);
    
    if (n % 2 == 0) return y * y;
    else return y * y * x;   
}

double myPow(double x, int n)
{
    return pow(x, n);
}


int main()
{
    cout<<myPow(2,10)<<endl;
    return 0;
}