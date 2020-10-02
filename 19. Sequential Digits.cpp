class Solution {
    private:
        vector<int> res;
        long low, high;
public:
    vector<int> sequentialDigits(int low, int high) {
        this->low = low;
        this->high = high;
        
        for(int i = 1; i <= 9; i += 1)
            generateSequence(0, i);
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void generateSequence(long num, int digit){
        if(num > high) return;
        if(low <= num && num <= high){
            res.push_back(num);
        }
        if(digit > 9) return;
        generateSequence(num*10 + digit, digit + 1);
        
    }
};