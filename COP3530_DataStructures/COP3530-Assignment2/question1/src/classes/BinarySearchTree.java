package classes;

public class BinarySearchTree
{
    private BinarySearchTreeNode root;
    public void insert(int key) {}
    public void delete(int key) {}
    public boolean find(int key) { return false;}    
    
    public void printPostorder(BinarySearchTreeNode node)
    {
        if(node != null)
        {
            printPostorder(node.left);
            printPostorder(node.right);
            System.out.printf("%d, ", node.key);
        }
    }
    
    public void printTree(BinarySearchTreeNode node)
    {
        if(node != null)
        {
            printTree(node.right);
            System.out.printf("%d, ", node.key);
            printTree(node.left);
        }
    }
    
    public int positiveKeySum (BinarySearchTreeNode node)
    {
        int sum = 0;
        if (node != null)
        {
            sum += positiveKeySum(node.left);
            sum += positiveKeySum(node.right);
            if(node.key > 0)
            {
                sum += node.key;
            }
        }
        return sum;
    } 
    
    public void deleteMax()
    {
        BinarySearchTreeNode currentNode = root;
        BinarySearchTreeNode currentParent = null;

        while (currentNode.right != null)
        {
            currentParent = currentNode;
            currentNode = currentNode.right;
        }
        if (currentNode.left != null)
        {
            BinarySearchTreeNode temp = currentNode.left;
            currentNode.left = null;
            currentParent.right = temp;
        }
        else
        {
            currentParent.right = null;
        }
    }
}