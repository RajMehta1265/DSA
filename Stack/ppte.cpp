#include<iostream>
using namespace std;

#define n 100

class stack
{
    int *arr;
    int top;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }

        top++;
        arr[top]=x;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"No value in stack"<<endl;
            return;
        }

        top--;
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"No element in stack";
            return -1;
        }
        return arr[top];
    }

};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();

    return 0;
}