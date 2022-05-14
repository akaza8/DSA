#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10]; 
int visited[10];
void dfs(int vertex){
    cout<<vertex<<endl;
    visited[vertex]=1;
    if(visited[vertex]==1) return;
    for(int child:graph[vertex]){
        cout<<"parent "<<vertex<<" child "<<child; 
        dfs(child);
    }
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);    
    return 0;
}