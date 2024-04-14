#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int> circularGameLosers(int n, int k) {
    vector<int> answer;
    unordered_map<int,int> map;
    for(int j=1; j<=n; j++) map[j] = 0;

    int i=1, round=1;
    map[i] = 1;
    while(map[i] <= 1){
        i += round*k;
        i = ((i%n) ? (i%n) : (n));
        map[i]++;
        round++;
    }

    for(auto val : map){
        if(val.second == 0) answer.push_back(val.first);
        else continue;
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    vector<int>losers = circularGameLosers(4,4);

    for(auto i:losers){
        cout<<i<<" ";
    }   cout<<endl;

    return 0;
}