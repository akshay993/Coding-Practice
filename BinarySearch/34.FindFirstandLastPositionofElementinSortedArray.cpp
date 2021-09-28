/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
class Solution {
public:
    
    int searchFirstPosition(vector<int>&nums, int target){
        
        int low = 0;
        int high = nums.size() - 1;
        int index = -1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                index = mid;
            }
            if (nums[mid] >= target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        
        return index;        
    }
    
    int searchLastPosition(vector<int>&nums, int target){
        
        int low = 0;
        int high = nums.size() - 1;
        int index = -1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                index = mid;
            }
            if (nums[mid] <= target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result(2, -1);
        
        result[0] = searchFirstPosition(nums, target);
        
        if (result[0] == -1){
            return result;
        }
        
        result[1] = searchLastPosition(nums, target);
        return result;
    }
};