/*
286. Walls and Gates

You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.


Constraints:

m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
*/


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        int rows = rooms.size();
        int cols = rooms[0].size();
        const int INF = INT_MAX;
        
        queue<pair<int, int>> q;
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                
                if (rooms[row][col] == 0){
                    q.push({row, col});
                }                
            }                
        }
        
        if (q.size() == 0){
            return;
        }
        
        while (!q.empty()){
            
            int size = q.size();
            
            for (int i = 0; i < size; i++){
                
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                int curDist = rooms[row][col];                
                if (row - 1 >=0 && rooms[row-1][col] == INF){
                    rooms[row-1][col] = curDist + 1;
                    q.push({row-1, col});
                }
                if (row + 1 < rows && rooms[row+1][col] == INF){
                    rooms[row+1][col] = curDist + 1;
                    q.push({row+1, col});
                }
                if (col - 1 >= 0 && rooms[row][col-1] == INF){
                    rooms[row][col-1] = curDist + 1;
                    q.push({row, col-1});
                }
                if (col + 1 < cols && rooms[row][col+1] == INF){
                    rooms[row][col+1] = curDist + 1;
                    q.push({row, col+1});
                }                 
            }            
        }
    }
};