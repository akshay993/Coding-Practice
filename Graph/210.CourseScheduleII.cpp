/*
210. Course Schedule II
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

class Solution {
public:
    typedef unordered_map<int, vector<int>> graph;
    graph buildGraph(vector<vector<int>>& prerequisites){
        
        graph adjList;
        for (int i = 0; i < prerequisites.size(); i++){
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            adjList[from].push_back(to);
        }
        
        return adjList;
    }
    
    void topSort(int node, 
                 graph &adjList, 
                 vector<int>& state, 
                 stack<int>& st, 
                 bool& isPossible){
        state[node] = 1;
        vector<int> connectedNodes = adjList[node];
        
        for (int i = 0; i < connectedNodes.size(); i++){
            int curNode = connectedNodes[i];
            if (state[curNode] == 0){
                topSort(curNode, adjList, state, st, isPossible);
            } else if (state[curNode] == 1){
                isPossible = false;
                return;
            }            
        }
        
        state[node] = 2;
        st.push(node);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        graph adjList;
        vector<int> state(numCourses, 0);
        vector<int> result;
        stack<int> st;
        bool isPossible = true;
        
        adjList = buildGraph(prerequisites);
        
        for (int node = 0; node < numCourses; node++){
            if (state[node] == 0 && isPossible){
                topSort(node, adjList, state, st, isPossible);
            }
        }
        
        if (!isPossible){
            return result;
        }
        
        while (!st.empty()){
            result.push_back(st.top()); 
            st.pop();
        }
        
        return result;
    }
};