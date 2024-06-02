import java.util.ArrayList;
import java.util.List;

public class BinaryTreeNode {
    int label;
    BinaryTreeNode left;
    BinaryTreeNode right;

    BinaryTreeNode(int label, BinaryTreeNode left, BinaryTreeNode right) {
        this.label = label;
        this.left = left;
        this.right = right;
    }

    public void toPostorderString() {
        traversePostorder(this);
    }

    public List<Integer> toPostorderArrayString() {
        List<Integer> ret = new ArrayList<Integer>();
        toArrayPostorder(this, ret);
        return ret;
    }

    private static void toArrayPostorder(BinaryTreeNode binaryTreeNode, List<Integer> result) {
        if (binaryTreeNode == null) return;
        toArrayPostorder(binaryTreeNode.left, result);
        toArrayPostorder(binaryTreeNode.right, result);
        result.add(binaryTreeNode.label);
    }

    public static void traversePostorder(BinaryTreeNode binaryTreeNode) {
        if (binaryTreeNode == null) return;
        traversePostorder(binaryTreeNode.left);
        traversePostorder(binaryTreeNode.right);
        System.out.print(binaryTreeNode.label + " ");
    }
}
