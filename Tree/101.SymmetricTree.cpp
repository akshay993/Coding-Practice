/*
101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Constraints:

The number of nodes in the tree is in the range [1, 1000].
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
    bool isSymmetric(TreeNode* root) {
        
        return dfs(root, root);        
    }
    
    bool dfs(TreeNode* root1, TreeNode* root2){
        
        if (root1 == NULL && root2 == NULL){
            return true;
        }
        else if (root1 == NULL 
                 || root2 == NULL 
                 || root1->val != root2->val) {
            return false;
        }
        
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);        
    }
};