class Solution {
    private:
        int row, col;
        int walkCells = 0;
        int paths = 0;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        int x, y;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0){
                    walkCells += 1;
                }else if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        
        findPaths(grid, x+1, y, 0);
        findPaths(grid, x-1, y, 0);
        findPaths(grid, x, y+1, 0);
        findPaths(grid, x, y-1, 0);
        return paths;
        
    }
    
    void findPaths(vector<vector<int>> &grid, int x, int y, int steps){
        if(x >= row || x < 0 || y >= col || y < 0){
            return;
        }
        if(grid[x][y] == 2 && steps == walkCells){
            paths += 1;
            return;
        }
        
        if(grid[x][y] == 0){
            grid[x][y] = -1;
            findPaths(grid, x+1, y, steps+1);
            findPaths(grid, x-1, y, steps+1);
            findPaths(grid, x, y+1, steps+1);
            findPaths(grid, x, y-1, steps+1);
            grid[x][y] = 0;
        }
        
        
    }
};