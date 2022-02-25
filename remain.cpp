#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
int E,V;
int aarr[10];
int front=-1,rear=-1;
void enqueue(int x){
    if(front==rear==-1){
        front++;rear++;
        aarr[front]=x;
    }else{
        rear++;
        aarr[rear]=x;
    }
}
int dequeue(){
    return front++;
}
bool isempty(){
    return(front!=rear);
}
void Bfs(node* arry[],int arr[],int visited[]){
    cout<<"bfs traversal \n";
    visited[V]=0;
    node* t= arry[0];
    visited[0]=1;
    cout<<arr[0]<<" ";
    enqueue(arry[0]->data);
    while(!isempty()){
        for(int i=0;i<V;++i){
            int x = dequeue();
            cout<<arr[x]<<' ';
            while(arry[i]->next!=NULL){
                if(!visited[arry[i]->data]){
                enqueue(arry[i]->data);
                visited[arry[i]->data]=1;
                }arry[i]=arry[i]->next;
            }
        }
    }
}

node* lst(int arr[]){
    node* arry[V];for(int i=0;i<V;++i) arry[i]=NULL;
    for(int i=0;i<E;++i){
        cout<<"How many Edges connected to "<<i<<" th node ";
        int n;cin>>n;
        for(int j=0;j<n;++j){
            cout<<"enter edge (X->Y) "<<j<<"-> ";int v2;
            cin>>v2;
            node* nn=new node;
            nn->data=v2;
            nn->next=NULL;
            if(arry[v2]==NULL){
                arry[v2]=nn;
            }else{
               nn->next=arry[i];
               arry[i]->next=NULL;
               arry[i]=nn; 
            }
        }
    }
    int visited[V];
    Bfs(arry,arr,visited);
}
int main(){
    cout<<"how many vertices ";cin>>V;
    cout<<"enter no of edges ";cin>>E;
    int arr[V];
    for(int i=0;i<V;++i){
        cout<<"enter vertex "<<i<<" ";
        cin>>arr[i];
    } 
    lst(arr);
    return 0;
}
