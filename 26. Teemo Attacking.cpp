class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int res = 0;
        if(n == 0) return res;
        if(n == 1) return duration;
        
        int gap = 0;
        res = duration;
        for(int i = 1; i < n; i++){
            if(timeSeries[i] - timeSeries[i-1] >= duration){
                res += duration;
            }else{
                res += (timeSeries[i] - timeSeries[i-1]);
            }
        }
        
        return res;
    }
};