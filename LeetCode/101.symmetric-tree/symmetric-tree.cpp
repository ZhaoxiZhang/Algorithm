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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    bool isMirror(TreeNode *p, TreeNode *q){
        if (!p && !q)   return true;
        if (!p || !q)   return false;
        if (p->val == q->val){
            return isMirror(p->left, q->right) && isMirror(p->right, q->left);
        }
        return false;
    }
};