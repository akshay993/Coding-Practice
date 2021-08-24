/*
1020. Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/

class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {        
        
        int rows = grid.size();
        int cols = grid[0].size();
        int moves = 0;
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (row == 0 || col == 0 || row == rows - 1 || col == cols - 1){
                    explore(grid, row, col);
                }
            }
        }
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    moves++;
                }
            }
        }
        
        return moves;
    }
    
    void explore(vector<vector<int>>& grid, int row, int col){
        
        if (row >= 0 
            && col >=0 
            && row < grid.size() 
            && col < grid[0].size() 
            && grid[row][col] == 1){
            
            grid[row][col] = 0;
            explore(grid, row - 1, col);
            explore(grid, row + 1, col);
            explore(grid, row, col - 1);
            explore(grid, row, col + 1);
        }
    }
};