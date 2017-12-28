/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//9ms
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

//9ms
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr,*curr = root;
        stack<TreeNode*> store;

        while(!store.empty()||curr){
            while(curr){
                store.push(curr);
                curr=curr->left;
            }
            TreeNode* top = store.top();
            store.pop();
            if(!prev){
                prev = top;
            }else{
                if(prev->val>=top->val)
                    return false;
                prev = top;
            }
            curr=top->right;
        }
        return true;

    }
};