/*
547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

*/

class Solution {
public:
    
    void dfs(int node, 
             unordered_map<int, vector<int>>& adjList, 
             unordered_set<int>& visited){
        
        visited.insert(node);
        
        vector<int> connectedNodes = adjList[node];
        
        for (int i = 0; i < connectedNodes.size(); i++){
            
            int curNode = connectedNodes[i];            
            if (visited.find(curNode) == visited.end()){
                dfs(curNode, adjList, visited);
            }
        }        
    }
    
    unordered_map<int, vector<int>> createAdjList(vector<vector<int>>& isConnected){
     
        unordered_map<int, vector<int>> adjList;
        
        for (int i = 0; i < isConnected.size(); i++){
            
            vector<int> connection = isConnected[i];            
            for (int k = 0; k < connection.size(); k++){
                
                if (connection[k] == 1 && k != i){
                    adjList[i].push_back(k);                    
                }
            }            
        }
        
        return adjList;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;
        int count = 0;
        
        adjList = createAdjList(isConnected);
        
        int n = isConnected.size();
        
        for (int i = 0; i < n; i++){
            
            if (visited.find(i) == visited.end()){
                count++;
                dfs(i, adjList, visited);
            }
        }
        
        return count;
    }
};