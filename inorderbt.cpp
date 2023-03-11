#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newnode(int val)
{
    Node* temp=new Node;
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
void printInorder(struct Node* root)
{
    if(root!=NULL)
    {
        printInorder(root->left);
        cout<<root->data<<endl;
        printInorder(root->right);


    }
    else
    return;

}



int main()
{
    struct Node * root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    printInorder(root);
    return 0;
}