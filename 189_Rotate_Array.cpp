class Solution {
public:
    void reverse(vector<int>& v, int i, int j){
        while(i<j){
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);

        // auto it = nums.begin();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), next(it, k));
        // reverse(next(it, k), nums.end());
    }
};  