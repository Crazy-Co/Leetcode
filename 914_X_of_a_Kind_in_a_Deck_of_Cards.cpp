class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() == 1) return false;

        unordered_map<int,int> map;
        for(auto i:deck) map[i]++;
        vector<int> v;
        for(auto i:map) v.push_back(i.second);
        sort(v.begin(), v.end());

        int hcf=1;
        bool flag=true;

        for(int j=2; j<=v[0]; j++){
            for(int i=0; i<v.size(); i++){
                if(v[i]%j != 0){
                    flag = false;
                    break;
                }
            }
            if(flag) hcf=j;
            flag = true;
        }

        if(hcf == 1) return false;
        else return true;
    }
};