#include<iostream>
#include<Queue>
using namespace std;

queue<int> q1,q2;

void push(int x)
{
    q1.push(x);
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    queue<int> temp=q1;
    q1=q2;
    q2=temp;
}

int pop()
{
    q2.pop();
}

int main()
{
    int x,n;
    cin>>n;
    cout<<"Enter the values"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        push(x);
    }

    for(int i=0;i<n;i++)
    {
        cout<<q2.front()<<endl;
        pop();
    }


    return 0;
}