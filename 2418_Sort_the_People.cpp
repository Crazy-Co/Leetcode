class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();

        for(int i=1; i<n; i++){
            for(int j=n-1; j>i-1; j--){
                if(heights[j]>heights[j-1]){
                swap(heights[j], heights[j-1]);
                swap(names[j], names[j-1]);
                }
            }
        }
        return names;
    }
};