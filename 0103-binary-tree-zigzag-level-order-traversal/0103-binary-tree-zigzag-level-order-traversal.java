class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        boolean left_right = true;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int level = q.size();
            LinkedList<Integer> temp = new LinkedList<>();
            for (int i = 0; i < level; i++) {
                TreeNode curr = q.poll();
                if (left_right) {
                    temp.addLast(curr.val);
                } else {
                    temp.addFirst(curr.val);
                }

                if (curr.left != null) {
                    q.add(curr.left);
                }
                if (curr.right != null) {
                    q.add(curr.right);
                }
            }
            res.add(temp);
            left_right = !left_right; 
        }
        return res;
    }
}
