class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> s;

        for(auto i:nums) s.insert(i);
        
        auto it = s.begin();
        // [3,2,1]
        if(s.size() >= 3){
            it = next(it, 2); 
        }

        return *it;
    }
};