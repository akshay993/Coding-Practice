/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1] 

Constraints:
1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/

class Solution {
public:
    
    struct customCompare{
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }        
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> elementCount;
        
        for (int i = 0; i < n; i++){
            elementCount[nums[i]]++;
        }
        
        // <Number, Frequency/Count>
        priority_queue<pair<int, int>, vector<pair<int, int>>, customCompare> minHeap;       
        unordered_map<int, int>:: iterator it;
        
        for (it = elementCount.begin(); it != elementCount.end(); it++){
            minHeap.push({it->first, it->second});
            
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while (!minHeap.empty()){
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return result;
    }
};