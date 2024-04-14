#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string toPlainText(string s){
    int counter=0;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string str=s;
    for(int i=0; i<s.size(); i++){
        if(isalpha(s[i])){
            str[counter] = s[i];
            counter++;
        }
    }
    str = str.substr(0,counter);
    return str;
}


int isPalindrome(string s){
    int left=0;
    int right=s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            // cout<<s[left]<<s[right]<<endl;
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main()
{
    string s="A man, a plan, a canal: Panama";
    // string s=" ";
    string st = toPlainText(s);
    
    if(isPalindrome(st)){
        cout<<"Yes "<<st<<endl;
    }else{
        cout<<"No "<<st<<endl;
    }

 return 0;   
}