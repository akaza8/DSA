#include<bits/stdc++.h>
using namespace std;
int n,e;
int graph[10][10];
int visited[10];
int val[10];
void bfs(int vertex){
    cout<<val[vertex]<<" ";
    visited[vertex]=1;
    for(int i=0;i<n;++i){
        if(visited[i] == 0 && graph[vertex][i]==1){
            cout<<val[i]<<" ";
            visited[i]=1;
        }
        if(!visited[i])
        bfs(i);
    }
}
int main(){
    cout<<"enter no of vertices ";
    cin>>n;
    cout<<"enter no of edges ";
    cin>>e;
    for(int i=0;i<n;++i){
        cout<<"enter value "<<i+1<<" ";
        cin>>val[i];
    }
        cout<<"enter edges betn given vales ";
    for(int i=0;i<e;i++){
        int val1,val2;
        cin>>val1>>val2;
        int indx1,indx2;
        for(int j=0;j<n;++j){ 
            if(val[j]==val1) {
                indx1 = j;break;
            }
        }
        for(int k=0;k<n;++k){
            if(val[k]==val2) {
                indx2 = k;break;
            }
        }
        graph[indx1][indx2]=1;
        graph[indx2][indx1]=1;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    bfs(0);
    return 0;
}