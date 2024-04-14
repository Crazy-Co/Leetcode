// Recursion
class Solution {
public:
    int solve(int i, int size, vector<int> &nums){
        // basecase
        if(i >= size) return 0;

        int yes = nums[i]+solve(i+2, size, nums);
        int no = solve(i+1, size, nums);

        return max(yes, no);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(0, n, nums);
    }
};

// // Memoization
// class Solution {
// public:
//     int solve(int i, int size, vector<int> &nums, vector<int> &dp){
//         // basecase
//         if(i >= size) return 0;

//         if(dp[i+1] != -1) return dp[i+1];
//         int yes = nums[i]+solve(i+2, size, nums, dp);
//         int no = solve(i+1, size, nums, dp);

//         dp[i+1] = max(yes, no);
//         return dp[i+1];
//     }

//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1, -1);
//         return solve(0, n, nums, dp);
//     }
// };

// // Tabulation
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1,-1);
//         dp[0] = 0;
//         dp[1] = nums[0];
//         for(int i=2; i<=n; i++){
//                 dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
//             }
//         return dp[n];
//     }
// };

// // Space Optimization
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size(), i=0, j=nums[0];

//         for(int index=2; index<=n; index++){
//                 int temp=max(nums[index-1]+i,j);
//                 i=j;
//                 j=temp;
//             }
//         return j;
//     }
// };