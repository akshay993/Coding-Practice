/*
130. Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

class Solution {
public:
    void dfs (vector<vector<char>>& board, int row, int col){
        
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O'){
            return;
        }
        
        board[row][col] = 'M';
        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1); 
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (row == 0 || col == 0 || row == rows - 1 || col == cols -1){
                    dfs(board, row, col);
                }
            }
        }
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (board[row][col] == 'O'){
                    board[row][col] = 'X';
                }
                else if (board[row][col] == 'M'){
                    board[row][col] = 'O';
                }
            }
        }        
    }
};