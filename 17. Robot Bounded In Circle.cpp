class Solution {
public:
    bool isRobotBounded(string instructions) {
        int pos[2] = {0, 0};
        int dir[2] = {0, 1};
        
        for(char inst: instructions){
            if(inst == 'G'){
                pos[0] += dir[0];
                pos[1] += dir[1];
            }else if(inst == 'L'){
                swap(dir[0], dir[1]);
                dir[0] = -dir[0];
            }else if(inst == 'R'){
                swap(dir[0], dir[1]);
                dir[1] = -dir[1];
            }
        }
        
        
        if( (pos[0] == 0 && pos[1] == 0) || (dir[0] != 0 || dir[1] != 1) ){
            return true;
        }
        
        return false;
    }
};