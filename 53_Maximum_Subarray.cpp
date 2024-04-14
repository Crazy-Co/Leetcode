// We can observe that in the previous approach, dp[i] only depended on dp[i-1]. So do we really need to maintain the whole dp array of N elements? One might see the last line of previous solution and say that we needed all elements of dp at the end to find the maximum sum subarray. But we can simply optimize that by storing the max at each iteration instead of separately calculating it at the end.

// Thus, we only need to maintain curMax which is the maximum subarray sum ending at i and maxTillNow which is the maximum sum we have seen till now. And this way of solving this problem is what we popularly know as Kadane's Algorithm

// Kadane's Algorithm - O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int n = nums.size();

        int maxSum = INT_MIN;
        int currMax = 0;
        for(auto i:nums){
            currMax = max(currMax+i, i);
            maxSum = max(maxSum, currMax);
        }
        return maxSum;
    }
};


// Iterative Approach - O(N2)

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums){
//         int n = nums.size();
//         if(n == 1) return nums[0];

//         int maxSum = INT_MIN;
//         vector<int> arr(n+1,0);
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n-i; j++){
//                 arr[j] = nums[j]+arr[j+1];
//                 maxSum = max(maxSum, arr[j]);
//             }
//         }
//         return maxSum;
//     }
// };