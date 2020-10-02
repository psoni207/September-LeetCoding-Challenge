class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0){
            return 0;
        }
        
        int i = s.size()-1;
        while(i >= 0 && s[i] == ' ') i -= 1;
        
        int res = 0;
        while(i >= 0 && s[i] != ' '){
            res++;
            i -= 1;
        }
        
        return res;
        
    }
};