#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node*back;

    Node(int data1, Node *next1,Node *back1)
    {
        data = data1;
        next = next1;
        back=back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back=nullptr;
    }
};

Node *convert(vector<int> &arr)
{
    Node *head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
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

Node *insertAfter(Node *head, int k)
{
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the doubly linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect the new node to the last node in the list
    tail->next = newNode;
    newNode->back = tail;


    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convert(arr);
    head=insertAfter(head,12);
    print(head);

    return 0;
}
