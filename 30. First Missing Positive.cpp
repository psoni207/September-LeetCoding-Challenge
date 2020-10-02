class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0){
            return 1;
        }
        
        int n = nums.size();
        int flag = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                flag = 1;
            }
        }
        
        if(!flag){
            return 1;
        }
        
        
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            nums[abs(nums[i]) - 1] = -1*abs(nums[abs(nums[i]) - 1]);
        }
        
        int res = n + 1;
        for(int i = 0; i < n; i++){
            if(nums[i] >0 ){
                res = i + 1;
                break;
            }
        }
        
        return res;
        
    }
};