#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *appendnode(struct Node *head,int value)
{
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        return newnode;
    }
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
void printlist(struct Node* head)
{
    struct Node* current=head;
    while(current!=NULL)
    {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");

}
int main()
{
    struct Node *head=NULL;
    while(1)
    {
        printf("-----Menu------\n");
        printf("1)Insert Data in the linked list\n");
        printf("2)Display the linked list\n");
        printf("3)Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int value;
            printf("Enter the value: ");
            scanf("%d",&value);
            head=appendnode(head,value);
        }
        if(choice==2)
        {
            printf("Your linked list look like this \n ");
            printlist(head);
        }
        if(choice==3)
        {
            break;
        }
    }
    return 0;
}
