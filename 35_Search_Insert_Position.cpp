#include<iostream>
#include<vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low=0, high = n-1;
    int mid = (high+low)/2;
    while(low<=high){
        mid = (high+low)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            high = mid-1;
        }
        else if(nums[mid] < target){
            low = mid+1;
        }
    }
    if(target<nums[mid]) return mid;
    else return mid+1;
}

int main(){
    int target = 5;
    vector<int> v = {1,3,5,6};
    
    int index = searchInsert(v,target);
    cout << index << endl;

    return 0;
}