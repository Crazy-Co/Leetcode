#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void solve(int index, string digits, string output, string mapping[], vector<string> &ans){
        // base case
        if(index == digits.length()){
            ans.push_back(output);
            return;
        }
        for(int i=0; i<mapping[digits[index] - '0'].size(); i++){
            char letter = mapping[digits[index] - '0'][i];
            output.push_back(letter);
            solve(index+1, digits, output, mapping, ans);
            output.pop_back(); // back tracking
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        string output;
        vector<string> ans;
        if(digits.size() == 0) return ans;
        
        solve(index, digits, output, mapping, ans);
        return ans;
        }
};


int main(){
    Solution s;
    string digits = "687526";
    vector<string> combinations = s.letterCombinations(digits);
    
    for(auto i:combinations){
        cout<<i<<endl;
    }

    return 0;
}