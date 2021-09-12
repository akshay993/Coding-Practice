/*
934. Shortest Bridge

In a given 2D binary array grid, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

Constraints:
2 <= grid.length == grid[0].length <= 100
grid[i][j] == 0 or grid[i][j] == 1
*/

class Solution {
public:
    
    void paint(vector<vector<int>>& grid, int row, int col){
        
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1){
            return;
        }
        
        grid[row][col] = 2;
        paint(grid, row - 1, col);
        paint(grid, row + 1, col);
        paint(grid, row, col - 1);
        paint(grid, row, col + 1);        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        bool found = false;
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (!found && grid[row][col] == 1){
                    paint(grid, row, col);
                    found = true;
                }  else if (found && grid[row][col] == 1){
                    q.push({row, col});
                }             
            }
        }
        
        int level = 0;
        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++){
                    
                    int newRow = row + dir[k][0];
                    int newCol = col + dir[k][1];
                    
                    if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols){
                        continue;
                    } else if (grid[newRow][newCol] == 2){
                        return level;
                    } else if (grid[newRow][newCol] == 0){
                        grid[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }                    
                }                 
            }
            level++;            
        }
        
        return -1;
    }
};