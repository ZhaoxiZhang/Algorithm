/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    //4ms
    private List<Integer> list= new ArrayList<Integer>();
    public boolean isValidBST(TreeNode root) {
        inorder(root);
        int size = list.size();
        for (int i = 1;i < size;i++){
            if (list.get(i) <= list.get(i - 1))
                return  false;
        }
        return true;
    }
    void inorder(TreeNode root){
        if (root != null){
            inorder(root.left);
            list.add(root.val);
            inorder(root.right);
        }
    }
}