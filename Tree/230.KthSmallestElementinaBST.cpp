/*
230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
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
    
    int num, n;
    int kthSmallest(TreeNode* root, int k) {
        n = k;
        inorder(root);
        return num;
    }
    
    void inorder(TreeNode* root){
        if (root){
            inorder(root->left);
            if (n == 1){
                n--;
                num = root->val;
                return;
            }
            n--;
            inorder(root->right);
        }
    }
};