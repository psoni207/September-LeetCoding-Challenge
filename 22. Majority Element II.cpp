class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) return res;
        if (n == 1) 
        { 
            res.push_back(nums[0]); 
            return res;
        }
        
        bool flag1 = 0, flag2 = 0;
        int num1, num2;
        int cnt1 = 0, cnt2 = 0;
        
        for (int i = 0; i < n; i += 1){
            if(flag1 == 0 || num1 == nums[i]){
                num1 = nums[i];
                cnt1 += 1;
                flag1 = 1;
            }else if(flag2 == 0 || num2 == nums[i]){
                num2 = nums[i];
                cnt2 += 1;
                flag2 = 1;
            }else if (cnt1 == 0){
                num1 = nums[i];
                cnt1 = 1;
            }else if (cnt2 == 0){
                num2 = nums[i];
                cnt2 = 1;
            }else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
        
        cnt1 = 0; cnt2 = 0;
        for (int i = 0; i < n; i ++)
        {
            if (nums[i] == num1) cnt1 += 1;
            if (nums[i] == num2) cnt2 += 1;
        }
        
        if (cnt1 > n/3) res.push_back(num1);
        if (cnt2 > n/3) res.push_back(num2);
        
        return res;
        
    }
};