class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        ans[0] = 0;
        for(int i=1; i<=n; i++){
            int n=i;
            int count=0;
            while(n){
                if(ans[n] != -1){
                    count+=ans[n];
                    break;
                } 
                count+=n%2;
                n/=2;
            }
            ans[i]=count;
        }
            
        return ans;
    }
};