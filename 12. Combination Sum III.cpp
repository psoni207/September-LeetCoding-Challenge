class Solution {
    private:
    vector<vector<int> > res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n > 45 || k == 0){
            return res;
        }
        
        vector<int> ans;
        int sum = 0;
        int j = 1;
        helperSolve(k, n, ans, sum, j);
        
        return res;
    }
    
    void helperSolve(int k, int n, vector<int> &ans, int sum, int j){
        if(ans.size() == k && sum == n){
            res.push_back(ans);
            return;
        }
        
        for(int i = j; i <= 9; i++){
            if(sum + i <= n){
                ans.push_back(i);
                helperSolve(k, n, ans, sum + i, i+1);
                ans.pop_back();
            }    
        }
    }
};