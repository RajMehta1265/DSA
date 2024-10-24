#include <iostream>
using namespace std;

class CircularLink
{
public:
    int data;
    CircularLink *next;

    CircularLink(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void print(CircularLink *head)
{
    if (head == nullptr)
        return;
    CircularLink *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    int n, x, data;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The list must have at least one node." << endl;
        return 0;
    }

    cout << "Enter the data for node 1: ";
    cin >> data;
    CircularLink *head = new CircularLink(data);
    CircularLink *temp = head;

    for (int i = 2; i <= n; i++)
    {
        cout << "Enter the data for node " << i << ": ";
        cin >> data;
        temp->next = new CircularLink(data);
        temp = temp->next;
    }
    temp->next = head; 

    cout << "Original List: ";
    print(head);

    cout << "Rotated List: ";
    print(head);

    return 0;
}
