#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

// Function to insert a value into a binary search tree (BST)
void insert(TreeNode *root, TreeNode *New)
{
    if (New->data > root->data)
    {
        if (root->right == nullptr)
            root->right = New;
        else
            insert(root->right, New);
    }
    if (New->data < root->data)
    {
        if (root->left == nullptr)
            root->left = New;
        else
            insert(root->left, New);
    }
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function to find the minimum value node in a BST
TreeNode *findMin(TreeNode *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// Function to delete a node with the specified value from the BST
TreeNode *deleteNode(TreeNode *root, int val)
{
    if (root == nullptr)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        TreeNode *temp = findMin(root->right);

        // Copy the in-order successor's value to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(5);

    // Insert additional values into the BST
    insert(root, new TreeNode(3));
    insert(root, new TreeNode(8));
    insert(root, new TreeNode(2));
    insert(root, new TreeNode(4));
    insert(root, new TreeNode(6));
    insert(root, new TreeNode(10));

    // Perform an in-order traversal to display the BST
    cout << "In-order traversal of the BST:" << endl;
    inOrderTraversal(root);
    cout << endl;

    // Delete a node (e.g., value 3)
    int valueToDelete = 3;
    root = deleteNode(root, valueToDelete);

    cout << "BST after deleting value " << valueToDelete << ":" << endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
