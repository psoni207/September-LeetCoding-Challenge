class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        if(S.size() == 0){
            return ans;
        }
        
        unordered_set<char> seen;
        vector<int> freq(26, 0);
        
        for(char ch: S){
            freq[ch-'a'] += 1;
        }
        
        int count = 0;
        for(char ch: S){
            count += 1;
            seen.insert(ch);
            
            freq[ch - 'a'] -= 1;
            if(freq[ch -'a'] == 0){
                seen.erase(ch);
                if(seen.empty()){
                    ans.push_back(count);
                    count = 0;
                }
            }
        }
        return ans;
        
    }
};
