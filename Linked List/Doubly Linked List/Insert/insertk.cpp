#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertathead(Node *head, int k)
{
    Node* newNode = new Node(k);

    if (head == nullptr) {
        return newNode;
    }

    newNode->next = head;
    head->back = newNode;
    head = newNode;

    return head;
}

Node *insertk(Node *head, int k, int pos)
{
    Node* newNode = new Node(k);

    if (pos == 0) {
        return insertathead(head, k);
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return head;
    }

    newNode->next = temp->next;
    newNode->back = temp;

    if (temp->next != nullptr) {
        temp->next->back = newNode;
    }

    temp->next = newNode;

    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convert(arr);
    head = insertathead(head, 14);
    print(head);

    head = insertk(head, 10, 2);
    print(head);

    return 0;
}
