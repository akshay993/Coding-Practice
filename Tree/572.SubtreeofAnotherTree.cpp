/*
572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (subRoot == NULL){
            return true;
        }
        
        if (root == NULL){
            return false;
        }
        
        if (isIdentical(root, subRoot)){
            return true;
        }            
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isIdentical(TreeNode* root1, TreeNode* root2){
        
        if (root1 == NULL && root2 == NULL){
            return true;
        }
        
        if (root1 == NULL || root2 == NULL || root1->val != root2->val){
            return false;
        }
        
        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
};