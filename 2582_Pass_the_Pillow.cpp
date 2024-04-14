#include<iostream>
using namespace std;

int passThePillow(int n, int t) {
    int i = 1;

    // while(t) // this will cause unexpected results
    while(t>0)
    {
        if(n>t){
            if(i==1) i = 1+t;
            else if(i==n) i = n-t;
            // if(i==n) i = n-t; // this will cause unexpected results

            t=0;
        }
        else if(n<=t){
            if(i==1) i = n;
            else if(i==n) i = 1;
            // if(i==n) i = 1; // this will cause unexpected results
            
            t = t-n+1;
        }
    }
    return i;
}

int main(){
    int i = passThePillow(5, 12);
    cout<<i<<endl;

    return 0;
}