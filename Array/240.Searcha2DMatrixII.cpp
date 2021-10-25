/*
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size() - 1;
        int col = 0;
        
        while (row >= 0 && col < matrix[0].size()){
            
            if (matrix[row][col] < target){
                col++;
            } else if (matrix[row][col] > target){
                row--;
            } else{
                return true;
            }            
        }
        
        return false;
    }
};