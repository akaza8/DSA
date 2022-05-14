#include<bits/stdc++.h>
using namespace std;
int graph[10][10];int visited[10];
queue<int>q;
void bfs(int vertex){
    q.push(vertex);
    visited[vertex]=1;
    while(!q.empty()){
       int x;x=q.front();q.pop();cout<<x<<" ";
       for(int i=1;i<=10;i++){
        if(!visited[i] && graph[x][i]==1){
            q.push(i);visited[i]=1;
        }
       }
    }
}
int main(){
    int n,m;
    cout<<"vertex ";cin>>n;
    cout<<"edges ";cin>>m;
    for(int i=1;i<=m;++i){
        int v1,v2;
        cout<<"edge"<<i<<" ";
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    bfs(1);
    return 0;
}