/*
314. Binary Tree Vertical Order Traversal

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if (root == NULL){
            return result;
        }
        
        unordered_map<int, vector<int>> columnMap;
        
        queue<pair<TreeNode*, int>> q;
        int minCol = 0;
        int maxCol = 0;
        q.push({root, 0});
        
        while (!q.empty()){
            
            TreeNode* node = q.front().first;
            int column = q.front().second;
            q.pop();
            columnMap[column].push_back(node->val);
            
            if (node->left){
                q.push({node->left, column - 1});
            }
            if (node->right){
                q.push({node->right, column + 1});
            }
            
            minCol = min(minCol, column);
            maxCol = max(maxCol, column);
        }
        
        for (int i = minCol; i <= maxCol; i++){
            result.push_back(columnMap[i]);
        }
        
        return result;
    }
};