class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int res = nums[0];
        int minProd = nums[0];
        int maxProd = nums[0];
    
        for(int i = 1; i < n; i++) {
            int temp = maxProd;
        
            maxProd = max({nums[i], maxProd * nums[i], minProd * nums[i]});
            minProd = min({nums[i], temp * nums[i], minProd * nums[i]});
            
            res = max(res, maxProd);
        }
        
        return res;
        
    }
};