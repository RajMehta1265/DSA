#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *queue;
    int front, rear, size, capacity;

public:
    CircularQueue(int c)
    {
        capacity = c;
        queue = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~CircularQueue()
    {
        delete[] queue;
    }

    bool isFull()
    {
        return (size == capacity);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = value;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
        return value;
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.displayQueue();

    q.dequeue();
    q.dequeue();

    q.displayQueue();

    q.enqueue(60);
    q.enqueue(70);

    q.displayQueue();

    return 0;
}
