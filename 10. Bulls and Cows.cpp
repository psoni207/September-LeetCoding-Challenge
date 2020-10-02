class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> umap;
        
        for(char ch: secret){
            umap[ch] += 1;
        }
        
        string res = "";
        int n = secret.size();
        
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0; i < n; i++){
            if(guess[i] == secret[i]){
                umap[guess[i]] -= 1;
                bulls += 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            if( guess[i] != secret[i] && umap.find(guess[i]) != umap.end() && umap[guess[i]] >= 1){
                umap[guess[i]] -= 1;
                cows += 1;
            }
        }
        
        res += to_string(bulls) + "A" + to_string(cows) + "B";
        
        return res;
        
    }
};