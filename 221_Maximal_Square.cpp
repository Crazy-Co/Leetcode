class Solution {
public:
    int solve(vector<vector<char>>& matrix, int row, int col, int &maxi){
        if(row >= matrix.size() ||  col >= matrix[0].size()){
            return 0;
        }
        
        int right = solve(matrix, row, col+1, maxi);
        int diag = solve(matrix, row+1, col+1, maxi);
        int down = solve(matrix, row+1, col, maxi);

        if(matrix[row][col] == '1'){
            int ans = 1 + min(right, min(diag, down));
            maxi = max(maxi, ans);
            return ans;
        }else{
            return 0;
        }
    }

    int solveMem(vector<vector<char>>& matrix, int row, int col, int &maxi, vector<vector<int>>& dp){
        if(row >= matrix.size() ||  col >= matrix[0].size()){
            return 0;
        }
        
        if(dp[row][col] != -1) return dp[row][col];

        int right = solveMem(matrix, row, col+1, maxi, dp);
        int diag = solveMem(matrix, row+1, col+1, maxi, dp);
        int down = solveMem(matrix, row+1, col, maxi, dp);

        if(matrix[row][col] == '1'){
            dp[row][col] = 1 + min(right, min(diag, down));
            maxi = max(maxi, dp[row][col]);
            return dp[row][col];
        }else{
            return dp[row][col] = 0;
        }
    }

    int solveTab(vector<vector<char>> &matrix, int &maxi){
        int row = matrix.size();
        int col = matrix[0].size();
        // dp array initialization
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){

                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // using Recursion
        // int maxi=0;
        // solve(matrix, 0, 0, maxi);
        // return maxi*maxi;

        // using Memoization
        // top-down approach
        // int maxi=0;
        // vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        // solveMem(matrix, 0, 0, maxi, dp);
        // return maxi*maxi;

        // using Tabulation
        // bottom-up approach
        int maxi=0;
        solveTab(matrix, maxi);
        return maxi*maxi;

    }
};