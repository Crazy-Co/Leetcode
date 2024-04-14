class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0; 

        for(int i=0; i<n; i++){
            if(i>reachable) break;
            reachable = max(nums[i]+i, reachable);
        }
        
        if(reachable >= n-1) return true;
        else return false;
    }
};