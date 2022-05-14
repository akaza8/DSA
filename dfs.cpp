#include<bits/stdc++.h>
using namespace std;
int graph[10][10];int visited[10];
void dfs(int vertex){
    visited[vertex]=1;
    cout<<vertex<<" ";
    for(int j=1;j<=10;++j){
        if(!visited[j]&&graph[vertex][j]==1){
            dfs(j);
        }
    }
}
int main(){
    cout<<"how many vertices and edges ";
    int n,m;cin>>n>>m;
    cout<<"enter matrix ";
    for(int i=1;i<=m;i++){
        int v1,v2;
        L:cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    } 
    dfs(1);   
    return 0;
}