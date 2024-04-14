class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        if(nums1.size() == 0 || nums2.size() == 0) return v;

        set<int> s1;
        set<int> s2;
        for(auto i:nums1) s1.insert(i);
        for(auto i:nums2) s2.insert(i);

        for(auto i:s1){
            if(s2.count(i)) v.push_back(i);
        }
        return v;
    }
};