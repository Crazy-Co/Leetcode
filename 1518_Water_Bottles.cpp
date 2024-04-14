#include<iostream>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0, empty=0, rem=0;

    while(numBottles != 0){
        ans+=numBottles;
        empty = numBottles+rem;

        if(empty >= numExchange){
            rem = empty%numExchange;
            numBottles = empty/numExchange;
        }
        else{
            numBottles = 0;
        }
    }

    return ans;
}

int main(){
    int bottle, exchange;
    cin>>bottle>>exchange;

    cout<<"Number of Bottles we can drink is "<<numWaterBottles(bottle, exchange)<<endl;
}