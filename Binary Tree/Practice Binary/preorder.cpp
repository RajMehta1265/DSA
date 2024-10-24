#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        left = right = nullptr;
        data = d;
    }
};

void preorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

vector<int> preOrder(Node *root)
{
    vector<int> arr;
    preorder(root, arr);
    return arr;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(10);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    vector<int> result = preOrder(root);

    cout << "Preorder Traversal: ";

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}