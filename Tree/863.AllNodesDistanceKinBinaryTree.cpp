/*
863. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void preorder(TreeNode* node, 
                  TreeNode* par, 
                  unordered_map<TreeNode*, TreeNode*>& parent){
        
        if (node){
            parent[node] = par;
            preorder(node->left, node, parent);
            preorder(node->right, node, parent);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parent;    
        unordered_set<TreeNode*> visited;
        
        preorder(root, NULL, parent);
        
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int level = 0;
        
        while (!q.empty()){            
            if (level++ == k){
                break;
            }
            int size = q.size();
            
            for (int i = 0; i < size; i++){                
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                
                TreeNode* parentNode = parent[node];                
                if (parentNode != NULL && visited.find(parentNode) == visited.end()){
                    q.push(parentNode);
                    visited.insert(parentNode);
                }
            }
        }
        
        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};