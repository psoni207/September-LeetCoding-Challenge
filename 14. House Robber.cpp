class Solution {
    private:
        int n;
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int res;
        res = helperSolve(nums);
        
        return res;
    }
    
    int helperSolve(vector<int> &nums){
        vector<int> dp(n+1,0);
        dp[1] = nums[0];
        
        for(int i = 1; i < n; i++){
            dp[i+1] = max(nums[i]+dp[i-1], dp[i]);
        }
        
        return dp[n];
    }
};