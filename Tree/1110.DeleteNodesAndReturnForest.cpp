/*
1110. Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

Constraints:
The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
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
    void dfs(TreeNode* &root, unordered_set<int> &deleteNodes){
        
        if (root){
            
            dfs(root->left, deleteNodes);
            dfs(root->right, deleteNodes);
            
            if (deleteNodes.find(root->val) != deleteNodes.end()){
                
                if (root->left)
                    result.push_back(root->left);                
                if (root->right)
                    result.push_back(root->right);
                
                root = NULL;                            
            }            
        }        
    }
    
    vector<TreeNode*> result;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> deleteNodes(to_delete.begin(), to_delete.end());        
        dfs(root, deleteNodes);    
        
        if (root)
            result.push_back(root);        
        
        return result;        
    }
};