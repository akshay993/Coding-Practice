/*
128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Ex -
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Constraints
0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0)
            return 0;
        
        int longestSeq = 1;
        int currentSeq = 1;
        
        sort(nums.begin(), nums.end());
        
        for (int i=1; i<nums.size(); i++){
            
            if (nums[i] != nums[i-1]){
                
                if (nums[i] == nums[i-1]+1){
                    currentSeq += 1;
                }
                else{
                    longestSeq = max(longestSeq, currentSeq);
                    currentSeq = 1;
                }
            }
        }
        
        return max(longestSeq, currentSeq);
    }
};