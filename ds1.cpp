#include<iostream>
using namespace std;
class Node
{
   public:
    int data;
    Node *next;
};

//Given a pointer to the head pointer and data value, insert data at the head
void insertFirst(Node** head,int data)
{
//1. allocate memory to a new node
    Node* node=new Node();
    //2.initialize the new node variables
    node->data=data;
    node->next=NULL;
    //3.update the values
    node->next=(*head);
    (*head)=node;
    //printlist(*head);
}
void insertLast(Node** head,int data)
{
    Node* node=new Node();
    Node* last=(*head);
    node->data=data;
    node->next=NULL;
    if(head==NULL)
    {
       (*head)=node;  
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;

    }
    last->next=node;
   // printlist(*head);
    return;
}

void insertAfter(Node* node, int data )
{
    Node* newnode=new Node();
    newnode->data=data;
    newnode->next=NULL;
    if(node==NULL)
    {
        cout<<"prev node cant be null";
        return;

    }
    newnode->next=node->next;
    node->next=newnode;
    //printlist(*head);
}
void printlist(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<endl;
        node=node->next;

    }

}
//ITERATIVE APPROACH OF SEARCHING AN ELEMENT IN AN LL
bool searchIterative(Node * head,int x)
{
    Node* current= head;
    while(current!=NULL)
    {
        if(current->data==x)
            return true;
    current=current->next;
    }
    return false;

}
//RECURSIVE APPROACH OF SEARCH 
bool searchRecursive(Node* head, int x)
{
    if(head==NULL)
        return false;
    if(head->data==x)
        return true;
    searchRecursive(head->next,x);
}
int lengthLL(Node* head)
{
    int count=0;
    if(head==NULL)
    return 0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
        
    }
return count;
}

int main()
{
    Node *head=NULL;
    insertFirst(&head,1);
    insertFirst(&head,2);
    insertLast(&head,3);
    printlist(head);
    insertAfter(head->next,4);
    printlist(head);
    searchIterative(head,30)?cout<<"yes"<<endl:cout<<"no"<<endl;
    searchRecursive(head,3)?cout<<"r YES"<<endl:cout<<"R NO"<<endl;
    int len=0;
    len=lengthLL(head);
    cout<<"len is"<<len<<endl;


}