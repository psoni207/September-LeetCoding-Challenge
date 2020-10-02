class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string res = "";
        
        if(n == 0) return res;
        
        int count = 0;
        for(int i = 0; i < n; i += 1){
            if(nums[i] != 0) break;
            else count += 1;
        }
        
        if(count == n){
            res = "0";
            return res;
        }
        
        sort(nums.begin(), nums.end(), compareFunc);
        
        for(int num: nums){
            res += to_string(num);
        }
        
        return res;
        
    }
    
    static bool compareFunc(const int &a, const int &b){
        string num1, num2;
        num1 = to_string(a) + to_string(b);
        num2 = to_string(b) + to_string(a);
        
        if(num1 >= num2){
            return true;
        }
        return false;
    }
};