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
        data = d;
        left = right = nullptr;
    }
};

void Postorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    Postorder(root->left, arr);
    Postorder(root->right, arr);
    arr.push_back(root->data);
}

vector<int> PostOrder(Node *root)
{
    vector<int> arr;
    Postorder(root, arr);
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

    vector<int> result = PostOrder(root);

    cout << "Postorder Traversal: ";

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}