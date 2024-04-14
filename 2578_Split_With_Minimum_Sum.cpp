class Solution {
public:
    int splitNum(int num) {
        vector<int>v;
        int n=num;
        while(n){
            v.push_back(n%10);
            n/=10;
        }

        sort(begin(v),end(v));
        int x=0,y=0;
        for(int i=0; i<v.size(); i++){
            if(i%2 == 0){
            x+=v[i];
            x*=10;
            } 
            else{
            y+=v[i];
            y*=10;
            } 
        }
        x/=10;
        y/=10;
        return x+y;
    }
};