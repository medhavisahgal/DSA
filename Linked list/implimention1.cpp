#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*next;
    //constructor
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
//& we are using pass by reference because
//we dont have to make a copy
//we have to do it in the original node
void insertathead(Node* &head,int value)
{
    Node *new_node= new Node(value);
    new_node->next=head;
    head=new_node;
}
void display(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
int main()
{
    Node* head=NULL;
    while(1)
    {
        cout<<"-----Menu------\n";
        cout<<"1)Insert Data in the linked list\n";
        cout<<"2)Display the linked list\n";
        cout<<"3)Exit\n";
        int choice;
        cout<<("Enter your choice: ");
        cin>>choice;
        if(choice==1)
        {
            int value;
            cout<<("Enter the value: ");
            cin>>value;
            insertathead(head,value);
        }
        if(choice==2)
        {
            cout<<("Your linked list look like this \n ");
            display(head);
        }
        if(choice==3)
        {
            break;
        }
    }
    return 0;
}
