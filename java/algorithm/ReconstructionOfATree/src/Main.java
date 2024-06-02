import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws RuntimeException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> preorder = new ArrayList<Integer>();
        List<Integer> inorder = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {
            preorder.add(sc.nextInt());
        }

        for (int i = 0; i < n; i++) {
            inorder.add(sc.nextInt());
        }

        try {
            BinaryTreeNode binaryTreeNode = makeBinaryTreeNode(preorder, inorder);
            List<Integer> ret = binaryTreeNode.toPostorderArrayString();
            String toStr = ret.stream()
                    .map(String::valueOf)
                    .collect(Collectors.joining(" "));
            System.out.println(toStr);
        } catch(Exception e) {
            System.out.println(e);
        }
    }

    private static BinaryTreeNode makeBinaryTreeNode(List<Integer> preorder, List<Integer> inorder) throws Exception {
        if(preorder.size() != inorder.size()) {
            throw new IndexOutOfBoundsException("It does not match arrays length.");
        }

        if (preorder.isEmpty()) {
            throw new IndexOutOfBoundsException("Something went wrong.");
        }

        int root = preorder.get(0);

        if (preorder.size() == 1) {
            return new BinaryTreeNode(root, null, null);
        }

        List<Integer> leftPreorder = new ArrayList<Integer>();
        List<Integer> rightPreorder = new ArrayList<Integer>();
        List<Integer> leftInorder = new ArrayList<Integer>();
        List<Integer> rightInorder = new ArrayList<Integer>();

        boolean found = false;
        for (int i = 0; i < preorder.size(); i++) {
            if (inorder.get(i) == root) {
                found = true;
                // leftInorder.add(inorder.get(i));
                continue;
            }

            if (found) {
                rightPreorder.add(preorder.get(i));
                rightInorder.add(inorder.get(i));
            } else {
                leftPreorder.add(preorder.get(i + 1));
                leftInorder.add(inorder.get(i));
            }
        }
        
        if (!found) {
            throw new Exception(root + " is not found!" + inorder.toString());
        }

        if (leftInorder.isEmpty()) {
            return new BinaryTreeNode(
                    root,
                    null,
                    makeBinaryTreeNode(rightPreorder, rightInorder)
            );
            // return makeBinaryTreeNode(rightPreorder, rightInorder);
        } else if (rightInorder.isEmpty()) {
            return new BinaryTreeNode(
                    root,
                    makeBinaryTreeNode(leftPreorder, leftInorder),
                    null
            );
            // return makeBinaryTreeNode(leftPreorder, leftInorder);
        } else {
            return new BinaryTreeNode(
                    root,
                    makeBinaryTreeNode(leftPreorder, leftInorder),
                    makeBinaryTreeNode(rightPreorder, rightInorder)
            );
        }
    }
}