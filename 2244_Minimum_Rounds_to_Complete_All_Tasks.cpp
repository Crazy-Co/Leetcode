class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rounds = 0;
        unordered_map<int,int> map;
        
        for(auto i:tasks) map[i]++;

        for(auto it = map.begin(); it != map.end(); it++){
            if((it->second) == 1) return -1;
            if((it->second)%3 != 0) rounds += ((it->second)/3) + 1;
            if((it->second)%3 == 0) rounds += ((it->second)/3);
        }

        return rounds;
    }
};