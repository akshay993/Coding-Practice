/*
973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Constraints:
1 <= k <= points.length <= 104
-104 < xi, yi < 104
*/
class Solution {
public:
    
    struct customCompare{
        
        bool operator()(vector<int>& p, vector<int>& q){
            return (p[0] * p[0] + p[1] * p[1]) > (q[0] * q[0] + q[1] * q[1]);
        }                
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, customCompare> minHeap;
        
        int n = points.size();
        
        for (int i = 0; i < n; i++){
            minHeap.push(points[i]);
        }
        
        for (int i = 0; i < k; i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return result;
    }
};