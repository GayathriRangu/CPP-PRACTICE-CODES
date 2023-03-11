#include<bits/stdc++.h>
using namespace std;
int visited[7]={0,0,0,0,0,0,0};
int a[7][7]={{0,1,1,1,0,0,0},{1,0,1,0,0,0,0},{1,1,0,1,1,0,0},{1,0,1,0,1,0,0},{0,0,1,1,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0}};
void DFS(int i)
{
    cout<<i<<endl;
    visited[i]=1;
    for(int j=0;j<7;j++)
    {
        if(a[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }

}
int main()
{
//DFS IMPLEMENTATION USING IN-BUILT STACK
DFS(1);//ONE-INDEXING
return 0;

}