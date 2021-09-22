/*
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Constraints:
The number of nodes in the tree is in the range [1, 100].
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
    
    void dfs(TreeNode* root, vector<string>& result, string path){
        
        if (root->left == NULL && root->right == NULL){
            result.push_back(path);
            return;
        }
        
        if (root->left){
            dfs(root->left, result, path + "->" + to_string(root->left->val));
        }
        
        if (root->right){
            dfs(root->right, result, path + "->" + to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {       
        vector<string> result;
        dfs(root, result, to_string(root->val));
        return result;
    }
};