class Solution {
public:
    // Recursion + Memoization
    // int solveMem(int i, vector<int> &cost, vector<int> &dp){
    //     // basecase
    //     if(i == 0 || i == 1){
    //         return 0;
    //     }
    
    //     if(dp[i] != -1) return dp[i];

    //     int prev1 = solve(i-1, cost, dp) + cost[i-1];
    //     int prev2 = solve(i-2, cost, dp) + cost[i-2];
    //     dp[i] = min(prev1, prev2);
    //     return dp[i];
    // }

    // Tabulation
    // int solveTab(int n, vector<int> &cost){
        // vector<int> dp(n+1, 0);

        // for(int i=2; i<=n; i++){
        //     dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        // }
        // return dp[n];
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        // Space Optimization
        int n = cost.size();
        int prev1 = 0;
        int prev2 = 0;

        for(int i=2; i<=n; i++){
            int curr = min(prev1+cost[i-1], prev2+cost[i-2]);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
        // return solveMem(n, cost, dp);
        // return solveTab(n, cost);
    }
};