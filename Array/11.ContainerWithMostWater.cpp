/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area = 0;
        int leftPtr = 0, rightPtr = height.size() - 1;
        
        while (leftPtr < rightPtr){
            
            int curHeight = min(height[leftPtr], height[rightPtr]);
            area = max(area, curHeight * (rightPtr - leftPtr));
            
            if (height[leftPtr] < height[rightPtr]){
                leftPtr++;
            } else{
                rightPtr--;
            }
        }
        
        return area;        
    }
};