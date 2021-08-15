/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

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
    vector<int> rightSideView(TreeNode* root) {        
        
        vector<int> result;
        
        if (root == NULL)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            
            int s = q.size();
            TreeNode* node = NULL;
            
            for (int i=0; i<s; i++){
             
                node = q.front();
                q.pop();
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);                
            }
            
            result.push_back(node->val);            
        }
        
        return result;
    }
};