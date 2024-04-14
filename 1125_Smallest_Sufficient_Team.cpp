class Solution {
public:
    void helper(int i, vector<int>& people_skill, int m, int mask, vector<int>& ans, vector<int>& team, vector<vector<int>>& dp){
        // base case
        if(i == people_skill.size()){
            if(mask == ((1<<m)-1)){
                if(team.size() == 0 || (ans.size() < team.size())) 
                team = ans; // better ans
            }
            return;
        }

        // memoization
        if(dp[i][mask] != -1){ 
            if(dp[i][mask] <= ans.size()) return;
        }

        helper(i+1, people_skill, m, mask, ans, team, dp);
        ans.push_back(i);

        helper(i+1, people_skill, m, (mask|people_skill[i]), ans, team, dp);
        ans.pop_back();

        if(ans.size() > 0) dp[i][mask] = ans.size();
    }


    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int> team;
        int n=people.size();
        int m=req_skills.size();

        unordered_map<string,int> map; 
        for(int i=0; i<m; i++){
            map[req_skills[i]] = (1<<i);
        }

        vector<int> people_skill;
        for(auto itr: people){
            int mask = 0;
            for(int j=0; j<itr.size(); j++){
                if(map.count(itr[j])) mask |= map[itr[j]];
            }
            people_skill.push_back(mask);
        }

        vector<vector<int>> dp(n, vector<int>((1<<m), -1));
        vector<int>ans;

        helper(0, people_skill, m, 0, ans, team, dp);
        return team;
    }   
};