/*
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:
1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution {
public:
    typedef unordered_map<int, vector<int>> graph;
    
    void topSort(int course, graph& adjList, vector<int>& state, bool& isPossible){
        
        state[course] = 1;
        vector<int> courses = adjList[course];
        
        for (int i = 0; i < courses.size(); i++){
            if (state[courses[i]] == 0){
                topSort(courses[i], adjList, state, isPossible);
            } else if (state[courses[i]] == 1){
                isPossible = false;
                return;
            }
        }        
        state[course] = 2;
    }
    
    graph buildGraph(vector<vector<int>>& prerequisites){
        
        graph adjList;        
        for (int i = 0; i < prerequisites.size(); i++){
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            adjList[from].push_back(to);
        }
        
        return adjList;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        graph adjList;
        vector<int> state(numCourses, 0);
        bool isPossible = true;
        
        adjList = buildGraph(prerequisites);
        
        for (int course = 0; course < numCourses; course++){
            if (!isPossible){
                return isPossible;
            } else if (state[course] == 0){
                topSort(course, adjList, state, isPossible);
            }            
        }
        
        return isPossible;
    }
};