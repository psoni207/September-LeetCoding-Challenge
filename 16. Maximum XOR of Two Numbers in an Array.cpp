class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0; 
        
        int n = nums.size();
        
        set<int> A; 
        
        for(int i = 30; i >= 0; i -= 1) {
        // set the i'th bit in mask like 100000, 110000, 111000.. 
            mask |= (1 << i); 
  
            for(int i = 0; i < n; i += 1) { 
  
                // Just keep the prefix till i'th bit neglecting all the bit's after i'th bit 
                A.insert(nums[i] & mask); 
            } 
  
            int maxRes = res | (1 << i); 
  
            for(int prefix : A) { 
  
                // find two pair in set such that a^b = maxRes which is the highest possible bit can be obtained 
                if(A.count(maxRes ^ prefix)) { 
                    res = maxRes; 
                    break; 
                } 
            } 
            A.clear(); 
        } 
  
        return res; 
    }
};