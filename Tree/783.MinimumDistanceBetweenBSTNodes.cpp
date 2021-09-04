/*
783. Minimum Distance Between BST Nodes

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
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
    TreeNode* prev;
    int ans;
    
    void inorder(TreeNode* root){        
        if (root){
            inorder(root->left);
            if (prev != NULL){
                ans = min(ans, root->val - prev->val);                
            }
            prev = root;
            inorder(root->right);
        }
    }
    
    int minDiffInBST(TreeNode* root) {
        prev = NULL;
        ans = INT_MAX;
        inorder(root);
        return ans;
    }
};