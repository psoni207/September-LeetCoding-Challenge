class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> list1 = splitVersion(version1);
        vector<string> list2 = splitVersion(version2);
        
        int len1 = list1.size();
        int len2 = list2.size();
        int maxLen = max(len1, len2);
        
        for(int i = 0; i < maxLen; i += 1){
            int ver1 = (i < len1 ? toInt(list1[i]) : 0);
            int ver2 = (i < len2 ? toInt(list2[i]) : 0);
            
            if(ver1 > ver2) return 1;
            else if(ver1 < ver2) return -1;
        }
        
        return 0;
    }
    
    int toInt(string A){
        int num = 0;
        int n = A.size(), i = 0;
        
        while(i < n && A[i] == '0') i += 1;
        
        while(i < n){
            num = num*10 + (A[i] - '0'); 
            i += 1;
        }
        
        return num;
    }
    vector<string> splitVersion(string version){
        vector<string> res;
        string temp = "";
        
        for(int i = 0; i < version.size(); i += 1){
            if(version[i] == '.'){
                res.push_back(temp);
                temp = "";
            }else{
                temp += version[i];
            }
        }
        if(temp.size()) res.push_back(temp);
        
        return res;
    }
};