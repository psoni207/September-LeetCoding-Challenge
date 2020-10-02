class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        sort(trips.begin(), trips.end(), compareFunc);
        
        queue<int> fares;
        
        int total = 0;
        for(int i = 0; i < n; i++){
            
            int count = fares.size();
            while(count != 0){
                int pos = fares.front();
                fares.pop();
                if(trips[pos][2] <= trips[i][1]){
                    total -= trips[pos][0];
                }else{
                    fares.push(pos);
                }
                count -= 1;
            }
            if(total + trips[i][0] <= capacity){
                total += trips[i][0];
                fares.push(i);
            }else{
                return false;
            }
        }
        
        return true;
        
    }
    
    static bool compareFunc(const vector<int> &a, const vector<int> &b){
        if(a[1] < b[1] || (a[1] == b[1] && a[2] < b[2])){
            return true;
        }
        
        return false;
    }
};