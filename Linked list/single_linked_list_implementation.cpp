#include <bits/stdc++.h>
using namespace std; // Defining the structure of a node
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
// Implementing the linked list
class linkedlist
{
public:
    Node *head;
    linkedlist()
    {
        head = NULL;
    }
    // inserting a node at the end of the linked list
    void insertatend(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    // inserting a node at the beginning of the linked list
    void insertatbeginning(int value)
    {
        Node *newnode = new Node(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    // inserting a node at a given position in the linked list
    void insertatpos(int value, int pos)
    {
        Node *newnode = new Node(value);
        if (pos == 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position not found" << endl;
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    // deleting a node from the end of the linked list
    void deleteatend()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
    // deleting a node from the beginning of the linked list
    void deleteatbeginning()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // deleting a node from a given position in the linked list
    void deleteatpos(int pos)
    {
        if (head == NULL)
        {
            cout << "Empty linked list" << endl;
        }
        else if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Position does not exist" << endl;
            }
            else
            {
                Node *del = temp->next;
                temp->next = del->next;
                delete del;
            }
        }
    }
    // displaying the linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    linkedlist l;
    cout << "Number of elements that you want to insert in the linked list" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.insertatend(x);
    }
    cout << "Linked list is" << endl;
    l.display();
    // Menu driven program
    while (1)
    {
        cout << "Enter 1 to insert at the beginning" << endl;
        cout << "Enter 2 to insert at the end" << endl;
        cout << "Enter 3 to insert at a given position" << endl;
        cout << "Enter 4 to delete from the beginning" << endl;
        cout << "Enter 5 to delete from the end" << endl;
        cout << "Enter 6 to delete from a given position" << endl;
        cout << "Enter 7 to display the linked list" << endl;
        cout << "Enter 8 to exit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the element that you want to insert at the beginning" << endl;
            int x;
            cin >> x;
            l.insertatbeginning(x);
        }
        else if (choice == 2)
        {
            cout << "Enter the element that you want to insert at the end" << endl;
            int x;
            cin >> x;
            l.insertatend(x);
        }
        else if (choice == 3)
        {
            cout << "Enter the element that you want to insert" << endl;
            int x;
            cin >> x;
            cout << "Enter the position at which you want to insert" << endl;
            int pos;
            cin >> pos;
            l.insertatpos(x, pos);
        }
        else if (choice == 4)
        {
            l.deleteatbeginning();
        }
        else if (choice == 5)
        {
            l.deleteatend();
        }
        else if (choice == 6)
        {
            cout << "Enter the position that you want to delete" << endl;
            int pos;
            cin >> pos;
            l.deleteatpos(pos);
        }
        else if (choice == 7)
        {
            l.display();
        }
        else if (choice == 8)
        {
            break;
        }
    }
    return 0;
}
