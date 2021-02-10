public class Main {
    public static void main(String[] args) {
        System.out.printf("hello\n");
        BinaryTreeNode tree = new BinaryTreeNode(0);

       for(int i= 0; i<10; ++i)
           BinaryTreeNode.insert(tree,i+1);

        BinaryTreeNode.insert(tree,121);
        BinaryTreeNode.printInOrder(tree);

        System.out.printf("\nMax number = %d\n", BinaryTreeNode.maxInBinaryTree(tree));
        System.out.println(BinaryTreeNode.findInBinaryTree(tree,97));
        System.out.println(BinaryTreeNode.numberOfNodes(tree));
        System.out.println(BinaryTreeNode.depth(tree));

    }
}
