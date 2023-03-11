
#include<bits/stdc++.h>
using namespace std;
struct queu
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queu *q)
{
    if(q->r==q->f){
        return 1;
    }
    return 0;

}
int isFull(struct queu *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
return 0;
}
void enqueue(struct queu *q,int val)
{
    if(isFull(q))
    {
        cout<<"overflow"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r]=val;

    }

}
int dequeue(struct queu *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        cout<<"underflow"<<endl; 
           }
           else{
            q->f++;
            a=q->arr[q->f];

           }
           return a;

}
int main()
{
    struct queu q;
    q.size=50;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*(sizeof(int)));
    //BFS
    int u;
    int i=1; //specify indexing zero/one
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={{0,1,1,1,0,0,0},{1,0,1,0,0,0,0},{1,1,0,1,1,0,0},{1,0,1,0,1,0,0},{0,0,1,1,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0}};
    cout<<i<<endl;
    visited[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q))
    {
        int node=dequeue(&q);
        for(int j=0;j<7;j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                cout<<j<<endl;
                visited[j]=1;
                enqueue(&q,j);
            }


        }

    }
    
    return 0;


}