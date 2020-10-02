/*

class Trie{
    private:
        Trie *children[26];
        bool isWord;
    
    public:
    Trie(){
        isWord = false;
        for(int i = 0; i < 26; i += 1){
            children[i] = NULL;
        }
    }
    
    void insert(Trie *root, string word){
        Trie *node = root;
        for(int i = 0; i < word.size(); i += 1){
            if(node->children[word[i] - 'a'] == NULL){
                node->children[word[i] - 'a'] = new Trie();
            }
            node = node->children[word[i] - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(Trie *root, string word){
        Trie *node = root;
        for(int i = 0; i < word.size(); i += 1){
            if(node->children[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        
        if(node != NULL && node->isWord){
            return true;
        }
        return false;
    }   
};

class Solution {
    private:
        Trie *root;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        root = new Trie();
        for(int i = 0; i < wordDict.size(); i += 1){
            root->insert(root, wordDict[i]);
        }
        
        bool res = helperSolve(s);
        return res;
    }
    
    bool helperSolve(string word){
        int n = word.size();
        if(n == 0) return true;
        
        for(int i = 1; i <= n; i += 1){
            if( (root->search(root, word.substr(0,i) )) && helperSolve(word.substr(i, n-i)) ){
                return true;
            }
        }
        return false;
    }
};

*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string word = s;
        if(wordDict.size() == 0) return false;
        if(word.size() == 0) return true;
        
        int max_length = 0;
        for(int i = 0; i < wordDict.size(); i += 1) 
            if(wordDict[i].size() > max_length) max_length = wordDict[i].size();
        
        int n = word.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
      
        for(int i = 1;i <= n; i += 1)
        {
            for(int j = i-1; j >= max(i-max_length,0); j -= 1)
            {
                if(dp[j])
                {
                    string search = s.substr(j,i-j); //j...
                    if(find(wordDict.begin(),wordDict.end(),search) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};