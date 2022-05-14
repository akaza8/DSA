#include<bits/stdc++.h>
using namespace std;
struct listNode{
    int vertexno;
    listNode* next;
};
struct graph{
    int V;
    int E;
    listNode* adjency;
};
struct graph* adjelstGraph(){
    graph* G= new graph;
    listNode* temp ;
    cout<<"enter number of  vertices ";cin>>G->V;
    cout<<"enter number of vertices ";cin>>G->E;
    listNode* k = new listNode[G->V];
    G->adjency=k;
    for(int i=0;i<G->V;++i){
        G->adjency->vertexno=i;
        G->adjency->next=NULL;
        G->adjency++;
    }
    for(int i=0;i<G->E;++i){
        cout<<"enter edge (source to destination of 1st node ) ";
        int v;cin>>v;
        listNode* t = new listNode;
        t->vertexno=v;t->vertexno=NULL;

         
    }
}
int main(){
    
    return 0;
}