#include<iostream>
#include<vector>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> v(2);
    for(int i =0;i<n;i++){ //O(n^2)
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j] == target){
                    v[0]=i;
                    v[1]=j;
                }
            }
    }
    return v;  
}


int main(){
    vector<int> v = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(v,target);
    for(auto i:result) cout<<i<<" ";
    cout<<endl;
    
    return 0;
}