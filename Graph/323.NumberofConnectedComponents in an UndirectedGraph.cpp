/*
323. Number of Connected Components in an Undirected Graph

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

Example 1:
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 
Constraints:
1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.
*/
class Solution {
public:
    
    void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited){
        
        vector<int> connectedNodes = graph[node];
        for (int i = 0; i < connectedNodes.size(); i++){
            if (visited.find(connectedNodes[i]) == visited.end()){
                visited.insert(connectedNodes[i]);
                dfs(connectedNodes[i], graph, visited);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        
        int componentCount = 0;
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        
        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int node = 0; node < n; node++){
            if (visited.find(node) == visited.end()){
                visited.insert(node);
                componentCount++;
                dfs(node, graph, visited);
            }
        }
        
        return componentCount;
    }
};