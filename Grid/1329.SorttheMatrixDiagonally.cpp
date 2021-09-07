/*
1329. Sort the Matrix Diagonally

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                // ELements on same diagnol will have same (row - col) value
                m[row-col].push(mat[row][col]);
            }
        }
                
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                mat[row][col] = m[row-col].top();
                m[row-col].pop();
            }
        }
        
        return mat;
    }
};