/*
662. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.



Constraints:

The number of nodes in the tree is in the range [1, 3000].
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
    int widthOfBinaryTree(TreeNode* root) {
        
        int result = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()){            
            int count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result, end - start + 1);
            
            for (int i = 0; i < count; i++){
                TreeNode* node = q.front().first;
                int id = q.front().second - start;
                q.pop();
                if (node->left){
                    q.push({node->left, 2 * id + 1});
                }
                if (node->right){
                    q.push({node->right, 2 * id + 2});
                }                
            }            
        }
        
        return result;
    }
};