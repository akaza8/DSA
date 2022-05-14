#include<bits/stdc++.h>
using namespace std;
int graph[10][10];
int visited[10];stack<int>a;

void dfs(int vertex,int n){
    // visited[vertex]=1;
    // a.push(vertex);
    // for(int i=1;i<=10;++i){    
    //     if(!visited[i]&&graph[vertex][i]==1){
    //         dfs(i,n);
    //     }
    // }
    // for(int i=0;i<10;++i){
    //     int k=a.top();
    //     cout<<k<<" ";
    //     a.pop();                                                        
    // }
    a.push(vertex);
    while(!a.empty()){
        int x= a.top();
        a.pop();cout<<x<<" ";
        visited[x]=1;
        for(int i=1;i<=10;++i){
            if(i!=x){
            if(!visited[i]&&graph[x][i]==1){
                a.push(i);
                visited[i]=1;
            }}
        }
        // x=a.top();
    }
}
int main(){
    int n,m;
    cout<<"enter number of vertex and edges ";
    cin>>n>>m;
    cout<<"enter vertex1 &v2 reply in given time ";
    for(int j=1;j<=m;++j){
        int v1,v2;cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    dfs(1,n);
    return 0;
}