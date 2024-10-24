#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;

void push(int x)
{
    // Push new element onto s1
    s1.push(x);
}

int pop()
{
    // If s2 is empty, transfer elements from s1 to s2
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    // Pop element from s2
    int top_element = s2.top();
    s2.pop();
    return top_element;
}

int main()
{
    int x, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the values: " << endl;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(x);  // Push each element onto the queue
    }

    cout << "Dequeuing elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pop() << endl;  // Print each dequeued element
    }

    return 0;
}