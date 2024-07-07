#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main()
{
    cout<<"Enter the number of elements in the linked list: ";
    int n;
    cin>>n;
    cout<<"Enter the elements of the linked list: ";
    Node *head = nullptr;
    Node *temp = nullptr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        if (i == 0)
        {
            head = new Node(data);
            temp = head;
        }
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }
    cout<<"The linked list is: ";
    display(head);
    head = reverse(head);
    cout<<"The reversed linked list is: ";
    display(head);
    return 0;
}