#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;

    for(int i=0; i<numRows; i++){
        vector<int> vec(i+1,1);
        for(int j = 0; j<i+1; j++){
            if(j == 0 || j == i) vec[j] = 1;
            else{
                vec[j] = triangle[i-1][j] + triangle[i-1][j-1];
            }
        }
        triangle.push_back(vec);
    }  

    return triangle;
}

int main(){
    int n = 5;
    vector<vector<int>> pascal = generate(n);

    for(auto i:pascal){
        for(int j=0; j<n-1; j++){
            cout<<" ";
        }
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
        n--;
    } cout<<endl;

    return 0;
}