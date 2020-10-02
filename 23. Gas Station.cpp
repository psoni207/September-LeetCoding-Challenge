class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 0){
            return -1;
        }
        if(n == 1){
            return (gas[0] - cost[0] >= 0 ? 0 : -1);
        }
        
        int start = 0;
        int end = 1;
        
        int gasLeft = gas[0] - cost[0];
        
        //Running a loop till  starts meets end, meaning till our cycle gets completed
        while(start != end){
            //If the curr value is negative, then keep incrementing the start till it became positive
            while(gasLeft < 0 && start != end){
                
                //We need to remove the value of gasLeft start that we have added before
                gasLeft = gasLeft - (gas[start] - cost[start]);
                start = (start + 1) % n;
                
                //If we again come back to start, that means no solution exist and we return -1
                if(start == 0){
                    return -1;
                }
            }
            
            //Adding the gas that we got after visiting the current index
            gasLeft += gas[end] - cost[end];
            end = (end + 1) % n;
        }
        
        
        //If in the end, gasLeft is -ve that means it was impossible
        //to traverse  all the location and hence return -1
	    if(gasLeft < 0)
	        return -1;
        //If that's not the case, then we got the answer.
        return start; 
        
    }
};
