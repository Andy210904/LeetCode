/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static int diameter;
    public static int find_height(TreeNode root){
        if(root == null){
            return 0;
        }
        int left_height = find_height(root.left);
        int right_height = find_height(root.right);
        diameter = Math.max(diameter,left_height+right_height);

        return Math.max(left_height,right_height)+1;

    }
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        find_height(root);
        return diameter;
    }
}