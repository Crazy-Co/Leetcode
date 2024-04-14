#include<iostream>
using namespace std;


string convert(string s, int numRows) {
    string pattern = "";
    int n=s.size();
    int flag = 1;
    int down = numRows-1, up=0;
    if(n==1 || numRows == 1) return s;
    for(int i=0; i<numRows; i++){
        for(int j=i; j<n; ){
            pattern += s[j];

            if(flag==1){ 
                flag=0;
                if (down == 0) j+=up*2;
                else j+=down*2;
                }
            else if(flag==0){
                flag=1;
                if(up == 0) j+=down*2;
                else j+=up*2;
            }
        }
        down-=1;
        up+=1;
        flag=1;
    }
    return pattern;
}

int main(){
    string str = "PAYPALISHIRING";
    string pattern = convert(str,4);
    cout<<str<<endl;
    cout<<pattern<<endl;
    return 0;
}


// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I