/*
103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Constraints:

The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if (root == NULL){
            return result;
        }
        
        stack<TreeNode*> curLevel;        
        curLevel.push(root);
        bool leftToRight = true;
        
        while (!curLevel.empty()){
            
            int size = curLevel.size();
            vector<int> temp;
            stack<TreeNode*> nextLevel;
            
            for (int i = 0; i < size; i++){
                TreeNode* node = curLevel.top();
                curLevel.pop();
                temp.push_back(node->val);
                
                if (leftToRight){
                    if (node->left){
                        nextLevel.push(node->left);
                    }
                    if (node->right){
                        nextLevel.push(node->right);
                    }
                }
                else{
                    if (node->right){
                        nextLevel.push(node->right);
                    }
                    if (node->left){
                        nextLevel.push(node->left);
                    }
                }                
            }
            
            leftToRight = !leftToRight;
            result.push_back(temp);
            curLevel = nextLevel;            
        }
        
        return result;
    }
};