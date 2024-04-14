#include<iostream>
#include<unordered_map>
using namespace std;


int romanToInt(string s) {
    // int n=0;
    // for(int i = 0; i<s.size(); i++){
    //     if(s[i] == 'M'){
    //         n+=1000;
    //     }
    //     if(s[i] == 'D'){
    //         n+=500;
    //     }
    //     if(s[i] == 'C'){
    //         if(s[i+1] == 'D' || s[i+1] == 'M'){
    //             n-=100;
    //         }else n+=100;
    //     }
    //     if(s[i] == 'L'){
    //         n+=50;
    //     }
    //     if(s[i] == 'X'){
    //         if(s[i+1] == 'L' || s[i+1] == 'C'){
    //             n-=10;
    //         }else n+=10;
    //     }
    //     if(s[i] == 'V'){
    //         n+=5;
    //     }
    //     if(s[i] == 'I'){
    //         if(s[i+1] == 'V' || s[i+1] == 'X'){
    //             n-=1;
    //         }else n+=1;
    //     }
    // }
    // return n;

    
    unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    
    int n = s.length();
    int num = map[s[n - 1]];

    // VI = 5+1
    // IV = -1+5
    
    for (int i = n - 2; i >= 0; i--) {
        if (map[s[i]] >= map[s[i + 1]]) {
            num += map[s[i]];
        } else {
            num -= map[s[i]];
        }
    }
    
    return num;
}

int main(){

    string s = "MCMXCIV";

    cout<<s<<endl;
    cout<<romanToInt(s)<<endl;

    return 0;
}