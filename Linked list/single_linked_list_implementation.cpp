#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
void InsertAtStart(Node *&head, int val)
{
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}
void InsertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node();
    newNode->value = val;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void InsertAtPosition(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node();
    newNode->value = val;
    newNode->next = nullptr;
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        return;
    }

    Node *temp = head;
    int cnt = 0;
    while (cnt < pos - 1 && temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr)
    {
        cout << "Invalid Position!!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == nullptr)
    {
        tail = newNode;
    }
}
void DelFromSpepos(Node *&head, Node *&tail, int pos)
{
    int cnt = 0;
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "Empty List" << endl;
        return;
    }
    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return;
    }

    while (cnt < pos - 1 && temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Invalid position" << endl;
        return;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    if (temp2 == tail)
    {
        tail = temp;
    }
    delete temp2;
}
void dfst(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Already empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void dfend(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    tail = temp;
}
int len(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
Node *reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
// display function
void display(Node *&head)
{
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    while (temp)
    {
        cout << temp->value;
        if (temp->next)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // Performing basic operations
    // 1st making a linked list
    Node *head = nullptr;
    Node *tail = nullptr;
    while (true)
    {
        cout << "Choose from the menu" << endl;
        cout << "Press 1 TO CREATE A LINKED LIST" << endl;
        cout << "Press 2 TO INSERT A ELEMENT IN THE START" << endl;
        cout << "Press 3 TO INSERT A ELEMENT IN THE END" << endl;
        cout << "Press 4 TO INSERT ELEMENT AT A SPECIFIED POSITION" << endl;
        cout << "Press 5 TO DELETE AN ELEMENT FROM THE START" << endl;
        cout << "Press 6 TO DELETE AN ELEMENT FROM THE END" << endl;
        cout << "Press 7 TO DELETE AN ELEMENT AT A SPECIFIED POSITION" << endl;
        cout << "Press 8 to DELETE THE WHOLE LINKED LIST" << endl;
        cout << "Press 9 to DISPLAY THE LENGTH OF THE LINKED LIST" << endl;
        cout << "Press 10 to Reverse the Linked list" << endl;
        cout << "Press 11 DISPLAY YOUR LINKED LIST" << endl;
        cout << "Press 12 to EXIT " << endl;
        cout << "*----------------------END--------------------------*" << endl;
        int chs;
        cout << "Enter your choose ";
        cin >> chs;
        if (chs == 1)
        {
            int n;
            cout << "Enter the number of node you want to be in your linked list : ";
            cin >> n;
            cout << "Enter the elements" << endl;
            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                Node *newNode = new Node();
                newNode->value = val;
                newNode->next = nullptr;
                if (head == nullptr)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    // for connecting
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
        else if (chs == 2)
        {
            int val;
            cout << "Enter the element you want to add in the start : ";
            cin >> val;
            InsertAtStart(head, val);
        }
        else if (chs == 3)
        {
            int val;
            cout << "Enter the element you want to add in the end : ";
            cin >> val;
            InsertAtEnd(head, tail, val);
        }
        else if (chs == 4)
        {
            int val, pos;
            cout << "Enter the position you want to insert at in the linked list : ";
            cin >> pos;
            cout << "Enter the value : ";
            cin >> val;
            int len1 = len(head);
            InsertAtPosition(head, tail, pos - 1, val);
        }
        else if (chs == 5)
        {
            dfst(head);
        }
        else if (chs == 6)
        {
            dfend(head, tail);
        }
        else if (chs == 7)
        {
            int val, pos;
            cout << "Enter the position from where you want to delete the element from the LinkedList : ";
            cin >> pos;
            int len1 = len(head);
            DelFromSpepos(head, tail, pos - 1);
        }
        else if (chs == 8)
        {
            if (head == nullptr)
            {
                cout << "Already empty" << endl;
            }
            else
            {
                Node *temp = head;
                while (temp)
                {
                    Node *temp1 = temp;
                    temp = temp->next;
                    delete temp1;
                }
                head = nullptr;
                tail = nullptr;
                cout << "Linked List deleted" << endl;
            }
        }
        else if (chs == 9)
        {
            cout << "Your length of the linked list is : " << len(head) << endl;
        }
        else if (chs == 10)
        {
            head = reverse(head);
            cout << "Linked list reversed" << endl;
        }
        else if (chs == 11)
        {
            display(head);
        }
        else if (chs == 12)
        {
            break;
        }
    }

    return 0;
}
