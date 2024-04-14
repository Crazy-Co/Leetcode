#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector< vector<int> > triplet;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    if(n < 3)return triplet;
    // -4 -1 -1 0 1 2
    int i=0, j=n-1, k,sum;
    while(i<n-2){
        k=i+1;

        if (i > 0 && nums[i] == nums[i - 1]) {
            i++;
            continue; // Skip duplicates for i
        }

        a:
        sum = nums[i]+nums[j]+nums[k];
        if(sum == 0){
            vector <int> v;
            v.push_back(nums[i]);
            v.push_back(nums[k]);
            v.push_back(nums[j]);

            if (!(find(triplet.begin(), triplet.end(), v) != triplet.end()))            
            triplet.push_back(v);

            // Skip duplicates for j and k
            while (j < k && nums[j] == nums[j + 1]) {
                j++;
            }
            while (j < k && nums[k] == nums[k - 1]) {
                k--;
            }

            j--;
            if(j!=k) goto a;
        }
        else{
            if(sum > 0){
                j--;
                if(j!=k) goto a;
            }else if(sum < 0){
                k++;
                if(j!=k) goto a;
            }  
        }
        i++;
        j=n-1;
    }
    return triplet;
}

// vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> triplet;
//     sort(nums.begin(), nums.end());
//     int n = nums.size(); // Store the size of the vector in a variable
    
//     if (n < 3) {
//         return triplet;
//     }

//     for (int i = 0; i < n - 2; i++) { // Loop until n - 2 instead of using while loop
//         if (i > 0 && nums[i] == nums[i - 1]) {
//             continue; // Skip duplicates for i
//         }

//         int j = i + 1;
//         int k = n - 1;
        
//         while (j < k) {
//             int sum = nums[i] + nums[j] + nums[k];
            
//             if (sum == 0) {
//                 triplet.push_back({ nums[i], nums[j], nums[k] });
                
//                 // Skip duplicates for j and k
//                 while (j < k && nums[j] == nums[j + 1]) {
//                     j++;
//                 }
//                 while (j < k && nums[k] == nums[k - 1]) {
//                     k--;
//                 }
                
//                 j++;
//                 k--;
//             } else if (sum < 0) {
//                 j++;
//             } else {
//                 k--;
//             }
//         }
//     }

//     return triplet;
// }

int main() {
  vector<int> nums = {-1,0,1,2,-1,-4};
  sort(nums.begin(),nums.end());

  vector<vector<int>> triplet = threeSum(nums);

  for(auto i:triplet){
    for(auto j:i){
      cout<<j<<" ";
    } cout<<endl;
  } cout<<endl;

  return 0;
}
