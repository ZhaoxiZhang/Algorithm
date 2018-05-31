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
    private int cnt = 0;
    private int res = 0;
    public int kthSmallest(TreeNode root, int k) {
        findKthSmallest(root,k);
        return res;
    }

    public void findKthSmallest(TreeNode root,int k){
        if (root == null || cnt >= k)   return;
        findKthSmallest(root.left,k);
        cnt++;
        if (cnt == k){
            res = root.val;
        }
        findKthSmallest(root.right,k);
    }
}