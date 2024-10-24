#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convert(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node *removehead(Node *head)
{
    if(head==nullptr)
    {
        return head;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convert(arr);
    head=removehead(head);
    print(head);

    return 0;
}