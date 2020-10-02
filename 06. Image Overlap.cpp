class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        auto &A = img1;
        auto &B = img2;
        vector<int> LA, LB;
        
        const int N = A.size();
        const int base = 2*N-1;
        unordered_map<int, int> count;
        
        //Flatten the image
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(A[i][j] == 1) LA.push_back(i*base+j);
                if(B[i][j] == 1) LB.push_back(i*base+j);
            }
        }
        
        for(int i : LA){
          for (int j : LB){
              count[i - j] += 1;
          }
        }
        
        int res = 0;
        for (auto it : count) res = max(res, it.second);
        
        return res;
    }
};
/*
A = [1, 1, 1, 0]
B = [0, 1, 0, 1]
va = [0, 1, 2]
vb = [1, 3]

we compute the difference between each pair of the indexes

diff = [-1, 0, 1,
        -3, -2, -1]
frequency = {
    {-3, 1},
    {-2, 1},
    {-1, 2}, // -1 appeared twice
    {0, 1},
    {1, 1}
}

Since -1 is the most frequent difference and its frequency is 2
The best answer is to shift `B` by `-1` and we get `2` overlaps.

//The minimum value of the multiplier is the size of range of delta_y which is (N - 1) - -(N - 1) + 1 = 2 * N - 1.
*/