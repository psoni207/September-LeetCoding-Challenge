
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        
        long prod = 1;
        for(int i = 0 , j = 0; j < n; j += 1){
             prod *= nums[j];
            
            while(i < j && prod >= k) {
                prod /= nums[i++];
            } 
            if(prod < k){ 
                int len = j - i + 1 ; 
                res += len; 
            } 
        }
        
        return res;
    }
};