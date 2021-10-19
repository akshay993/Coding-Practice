/*
993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

Constraints:
The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.
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
    bool isCousins(TreeNode* root, int x, int y) {
        
        if (root->val == x || root->val == y){
            return false;
        }
        
        pair<TreeNode*, int> xNode;
        pair<TreeNode*, int> yNode;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, NULL});
        int level = 0;
        
        while (!q.empty()){
            int size= q.size();
            level++;
            
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                
                if (node->val == x){
                    xNode = {parent, level};
                }
                
                if (node->val == y){
                    yNode = {parent, level};
                }
                
                if (node->left){
                    q.push({node->left, node});
                }
                if (node->right){
                    q.push({node->right, node});
                }
            }
        }
        
        if (xNode.first != yNode.first && xNode.second == yNode.second){
            return true;
        }
        
        return false;
    }
};