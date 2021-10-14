/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.size() == 0){
            return NULL;
        }
        
        if (lists.size() == 1){
            return lists[0];
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < lists.size(); i++){
            
            ListNode* head = lists[i];            
            while (head != NULL){
                minHeap.push(head->val);
                head = head->next;
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        
        while (!minHeap.empty()){
            head->next = new ListNode(minHeap.top());
            minHeap.pop();
            head = head->next;
        }
        
        return dummy->next;
    }
};