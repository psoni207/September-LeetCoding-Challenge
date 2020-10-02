class Solution {
    private:
        string res = "";
        int SIZE = 4;
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string time = "";
        
        vector<bool> visited(SIZE, false);
        helperSolve(arr, visited, time);
        
        if(res.size() != 0)
            res = res.substr(0,2) + ':' + res.substr(2,2);
        
        return res;
    }
    
    void helperSolve(vector<int> &arr, vector<bool> &visited, string time){
        if(time.size() == SIZE && checkValidTime(time)){
            if(compareTime(time, res)){
                res = time;
            }
            return;
        }
        
        for(int i = 0; i < SIZE; i += 1){
            if(visited[i] == false){
                char ch = arr[i] + 48;
                visited[i] = true;
                helperSolve(arr, visited, time + ch);
                visited[i] = false;
                
            }
        }
    }
    
    bool checkValidTime(string &time){
        if(time[0] > '2'){
            return false;
        }
        if(time[0] == '2' && time[1] > '3'){
            return false;
        }
        if(time[2] > '5'){
            return false;
        }
        return true;
    }
    
    bool compareTime(string &a, string &b){
        if(b.size() == 0) return true;
        
        vector<int> check(SIZE);
        for(int i = 0; i < SIZE; i += 1){
            check[i] = a[i] - b[i];
        }
        
        for(int i = 0; i < SIZE; i += 1){
            if(check[i] > 0){
                return true;
            }else if(check[i] < 0){
                return false;
            }
        }
        
        return false;
    }
};