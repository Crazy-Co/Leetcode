class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            sort(grid[i].begin(),grid[i].end());
        }
        for(int i=grid[0].size()-1; i>=0; i--){
            int maxi=INT_MIN;
            for(int j=0; j<grid.size(); j++){
                maxi = max(grid[j][i],maxi);
                grid[j].pop_back();
            }
            ans += maxi;
        }
        return ans;
    }
};