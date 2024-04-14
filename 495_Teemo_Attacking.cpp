class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time=0;
        for(int i=1; i<timeSeries.size(); i++){
            if(timeSeries[i-1]+duration - 1 < timeSeries[i]){
                time+=duration;
            }else{
                time+=timeSeries[i]-timeSeries[i-1];
            }
        }
        time+=duration;
        return time;
    }
};