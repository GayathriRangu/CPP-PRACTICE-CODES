#include<iostream>
using namespace std;
struct Node
{
    int key;
    struct Node* next;
    Node(int key)
    {
        this->key=key;
        next=NULL;
    }

};
struct LinkedList
{
    Node* head;
    LinkedList()
    {
        head=NULL;
    }
Node* reverse(Node* head)
{
    if(head==NULL ||head->next==NULL)
        return head;
    Node* rest=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;

}
void printll()
{
    struct Node* temp=head;
 while(temp!=NULL)
 {
    cout<<temp->key<<endl;
    temp=temp->next;

 }

}
void push(int key)
{
    Node* n=new Node(key);
    n->next=head;
    head=n;
}

};
int main()
{
   LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.printll();
    ll.head=ll.reverse(ll.head);
    ll.printll();


}