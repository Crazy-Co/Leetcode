class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            // cycle sort
            if(nums[i] > 0 && nums[i] <= nums.size()){
                int j = nums[i] - 1;
                if(nums[i] != nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }else i++;
            }
            else i++;
        }

        // each element should follow (value = index+1) rule
        // first element to brake the rule is the first missing positive integer
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;

        // using hashtable

        // sort(nums.begin(),nums.end());
        // unordered_map<int,int> map;
        // for(auto i:nums) map[i]++;
        // int i=1;

        // while(1){
        //     if(map[i] != 0) i++;
        //     else return i;
        // }
    }
};