#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Implementing a queue using arrays
class MyQueue
{
private:
    vector<int> arr;
    int front, rear;

public:
    MyQueue()
    {
        front = -1;
        rear = -1;
    }
    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }
    // Function to add an element to the queue
    void enqueue(int data)
    {
        if (rear == -1 && front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        if (rear >= arr.size())
        {
            arr.resize(rear + 1);
        } // but with vector, this is not necessary
        arr[rear] = data;
    }
    // Function to remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        cout << "Dequeued element: " << arr[front - 1] << endl;
    }
    // Function to get the front element of the queue
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1; // or throw an exception
        }
        return arr[front];
    }
    // Function to get the rear element of the queue
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1; // or throw an exception
        }
        return arr[rear];
    }
    // Function to display the elements of the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    q.dequeue();
    q.display();
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
}