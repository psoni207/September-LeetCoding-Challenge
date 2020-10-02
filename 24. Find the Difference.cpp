class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for(char ch: s){
            freq[ch-'a'] += 1;
        }
        
        char res;
        for(char ch: t){
            if(freq[ch-'a'] == 0){
                res = ch;
                break;
            }else{
                freq[ch-'a'] -= 1;
            }
        }
        
        return res;
    }
};