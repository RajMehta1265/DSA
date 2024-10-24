#include <iostream>
using namespace std;

// Definition of TreeNode structure for a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

// Function to insert a value into a binary search tree (BST)
void insert(TreeNode* root, TreeNode* New) {
    if (New->data > root->data) {
        if (root->right == nullptr)
            root->right = New;
        else
            insert(root->right, New);
    }
    if (New->data < root->data) {
        if (root->left == nullptr)
            root->left = New;
        else
            insert(root->left, New);
    }
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    // Create a BST with an initial root node
    TreeNode* root = new TreeNode(5);

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

    return 0;
}