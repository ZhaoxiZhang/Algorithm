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
    vector<int>itv;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        unsigned int size = itv.size();
        for (unsigned int i = 1;i < size;i++){
            if (itv[i] <= itv[i - 1]){
                return false;
            }
        }
        return true;
    }

    void inorder(TreeNode* root){
        if (root != NULL){
            inorder(root->left);
            itv.push_back(root->val);
            inorder(root->right);
        }
    }
};