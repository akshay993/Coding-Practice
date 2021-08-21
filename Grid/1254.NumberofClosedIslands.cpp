/*
1254. Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1

*/

class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid, int row, int col){
        
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return false;
        }
        
        if (grid[row][col] == 1){
            return true;
        }
        
        grid[row][col] = 1;
        
        bool up = dfs(grid, row - 1, col);
        bool down = dfs(grid, row + 1, col);
        bool left = dfs(grid, row, col - 1);
        bool right = dfs(grid, row, col + 1);
        
        return up && down && left && right;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int result = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){                
                if (grid[row][col] == 0){
                    if (dfs(grid, row, col) == 1){
                        result++;
                    }
                }                
            }
        }
        
        return result;
    }
};