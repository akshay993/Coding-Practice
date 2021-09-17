/*
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
class Solution {
public:    
    void explore(vector<vector<char>>& grid, int row, int col)
    {        
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0'){
            return;
        }        
        grid[row][col] = '0';        
        explore(grid, row - 1, col);
        explore(grid, row + 1, col);
        explore(grid, row, col - 1);
        explore(grid, row, col + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();        
        int count = 0;
        
        for (int row = 0; row < rows; row++){        
            for (int col = 0; col < cols; col++){            
                if (grid[row][col] == '1'){
                    count++;
                    explore(grid, row, col);
                }
            }
        }
        
        return count;
    }
};