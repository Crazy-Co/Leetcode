class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // phod do
        stack<int> s;
        s.push(asteroids[0]);
        
        for(int i=1; i<asteroids.size(); i++){
            if(s.empty() || s.top() < 0) s.push(asteroids[i]);
            else if(s.top() > 0 && asteroids[i] > 0) s.push(asteroids[i]);
            else{
                if(abs(s.top()) > abs(asteroids[i])) continue;
                else{
                    if(abs(s.top()) < abs(asteroids[i])){
                        s.pop();
                        i--;
                    }else s.pop();
                }
            }
        }
        
    
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};