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

Node *deleteafter(Node *head)
{
    if (head == nullptr || head->next == NULL)
    {
        return head;
    }
    Node *prev = head;
    while (head->next->next != nullptr)
    {
        head = head->next;
    }
    delete head->next;
    head->next = nullptr;
    return prev;
}

Node *deletebefore(Node *head)
{
    if (head == nullptr || head->next == NULL)
    {
        return head;
    }
    Node *prev = head;
    head = head->next;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *deletek(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int count = 0;
    Node *knode = head;
    while (knode != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        knode = knode->next;
    }
    Node *prev = knode->back;
    Node *front = knode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return deletebefore(head);
    }
    else if (front == NULL)
    {
        return deleteafter(head);
    }
    prev->next = front;
    front->back = prev;

    knode->next = nullptr;
    knode->back = nullptr;
    delete knode;
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convert(arr);
    head = deletek(head,3);
    print(head);
    return 0;
}