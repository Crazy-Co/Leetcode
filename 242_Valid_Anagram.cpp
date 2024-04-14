class Solution {
public:
    bool isMapSame(unordered_map<char,int> map1, unordered_map<char,int> map2){
        for(auto pair:map1){ 
            if(map2[pair.first] != pair.second) return false;
            // map1 is not included in map2 -> false
        }
        return true;
        // map1 is included in map2 -> true
    }

    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;

        for(auto i:s) s_map[i]++;
        for(auto i:t) t_map[i]++;
        
        return isMapSame(s_map, t_map) && isMapSame(t_map, s_map);
    }
};