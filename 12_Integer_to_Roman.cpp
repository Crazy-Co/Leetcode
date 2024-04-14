#include<iostream>
#include<vector>
using namespace std;


string intToRoman(int num) {
    vector< pair<int,string> > dict = {
        {1000,"M"}, 
        {900,"CM"}, 
        {500,"D"}, 
        {400,"CD"}, 
        {100,"C"}, 
        {90,"XC"}, 
        {50,"L"}, 
        {40,"XL"}, 
        {10,"X"}, 
        {9,"IX"}, 
        {5,"V"}, 
        {4,"IV"}, 
        {1,"I"}
    };
    
    string s="";
    int n=num;
    
    for(int i=0; i<dict.size(); i++){
        while(n >= dict[i].first){
            s+=dict[i].second;
            n-=dict[i].first;
        }
    }
    
    return s;
}

int main(){
    int n=1947;
    cout<<n<<endl;
    cout<<intToRoman(n)<<endl;
    
    return 0;
}