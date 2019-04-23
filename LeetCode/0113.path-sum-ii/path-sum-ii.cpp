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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>path;
        findPaths(root, sum, path, res);
        return res;
    }

    void findPaths(TreeNode* node, int sum, vector<int>path, vector<vector<int>>& res){
        if (!node)  return;
        path.push_back(node->val);
        if (!node->left && !node->right && sum == node->val){
            res.push_back(path);
        }
        findPaths(node->left, sum - node->val, path, res);
        findPaths(node->right, sum - node->val, path, res);
    }
};