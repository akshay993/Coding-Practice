/*
226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

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
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == NULL){
            return root;
        }
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        root->left = right;
        root->right = left;
        
        return root;
    }
};