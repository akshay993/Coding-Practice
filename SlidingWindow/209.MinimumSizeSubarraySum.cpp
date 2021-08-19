/*
209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        if (nums.size() == 1 && nums[0] != target){
            return 0;
        }
        
        int left = 0, right = 0, runningSum = 0, minLength = INT_MAX;
        
        while (left <= right  && right < nums.size()){
            
            runningSum += nums[right];
            
            while (runningSum >= target){
                
                minLength = min(minLength, right - left + 1);
                runningSum -= nums[left];
                left++;                
            }
            
            right++;            
        }
        
        if (minLength == INT_MAX){
            return 0;
        }
        else{
            return minLength;
        }
    }
};