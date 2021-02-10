import java.util.LinkedList;

public class BinaryTreeNode {
    public int data;
    public BinaryTreeNode left, right;

    public BinaryTreeNode(int data){
        this.data = data;
        left = right = null;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public BinaryTreeNode getLeft() {
        return left;
    }

    public void setLeft(BinaryTreeNode left) {
        this.left = left;
    }

    public BinaryTreeNode getRight() {
        return right;
    }

    public void setRight(BinaryTreeNode right) {
        this.right = right;
    }

    public static void printPreOrder(BinaryTreeNode root){
        if(root != null){
            System.out.println(root.data);
            printPreOrder(root.left);
            printPreOrder(root.right);
        }
    }

    public static void printInOrder(BinaryTreeNode root){
        if(root != null){
            printInOrder(root.left);
            System.out.println(root.data);
            printInOrder(root.right);
        }
    }

    public static void printPostOrder(BinaryTreeNode root){
        if (root != null){
            printPostOrder(root.left);
            printPostOrder(root.left);
            System.out.println(root.data);
        }
    }

    public static int maxInBinaryTree(BinaryTreeNode root){
        int max = Integer.MIN_VALUE;

        if(root != null){
            int leftMax = maxInBinaryTree(root.left);
            int rightMax = maxInBinaryTree(root.right);

            max = Math.max(leftMax, rightMax);
            if(root.data > max)
                max = root.data;
        }
        return max;
    }

    public static boolean findInBinaryTree(BinaryTreeNode root,int data){
        if(root == null)
            return false;
        if(root.getData() == data)
            return true;
        return findInBinaryTree(root.getLeft(),data) || findInBinaryTree(root.getRight(),data);
    }

    public static BinaryTreeNode insert(BinaryTreeNode root,int data){
        if(root == null) return null;

        var queue = new LinkedList<BinaryTreeNode>();
        queue.offer(root);
        while(!queue.isEmpty()){
            BinaryTreeNode temp = queue.poll();
            if (temp != null){
                if (temp.getLeft() != null)
                    queue.offer(temp.getLeft());
                else{
                    temp.left = new BinaryTreeNode(data);
                    return root;
                }
                if (temp.right != null)
                    queue.offer(temp.right);
                else{
                    temp.right = new BinaryTreeNode(data);
                    return root;
                }
            }
        }
        return root;
    }

    public static int numberOfNodes(BinaryTreeNode root){
        int leftCount = root.left == null ? 0 : numberOfNodes(root.left);
        int rightCount = root.right == null ? 0 : numberOfNodes(root.right);
        return 1 + leftCount + rightCount;
    }

    public static int depth(BinaryTreeNode root){
        if (root == null) return 0;

        int leftDepth = depth(root.left);
        int rightDepth = depth(root.right);

        return (leftDepth > rightDepth) ? leftDepth+1 : rightDepth+1;
    }

    public static boolean hasPathSum(BinaryTreeNode root, int sum){
        if (root == null) return false;

        if (root.left == null && root.right == null && root.data == sum)
            return true;
        else
            return hasPathSum(root.left,sum - root.data) || hasPathSum(root.right,sum - root.data);
    }
}
