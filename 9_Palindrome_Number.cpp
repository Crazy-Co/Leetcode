#include<iostream>
#include<vector>
// #include<string>
using namespace std;

bool isPalindrome(int x) {
    if(x<0) return false;
    else{
        vector<int> v;
        while(x){
            v.push_back(x%10);
            x/=10;
        }
        int i=0, j=v.size()-1;
        while(i<j){
            if(v[i] != v[j]) return false;
            i++;
            j--;
        }
        return true;

        // if(x<0) return false;
        // else{
        //     string num = to_string(x);
        //     string rev = num;
        //     reverse(rev.begin(),rev.end());
        //     return num == rev;
        // }
    }
}
int main(){
    int x=123414321;
    cout<<(isPalindrome(x) ? "Yes":"No")<<endl;
    return 0;
}