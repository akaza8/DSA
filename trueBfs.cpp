#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
int E,V;
node* arry[15];
int visited[15];
int arr[15];
queue<int>aarr;
void Bfs(){
    aarr.push(0);
    while(!aarr.empty()){
        int x = aarr.front();aarr.pop();
        cout<<arr[x]<<" ";
        visited[x]=1;
        while(arry[x]!=NULL){
            if(!visited[arry[x]->data]){
            aarr.push(arry[x]->data);
            visited[arry[x]->data]=1;}                         
            arry[x]=arry[x]->next;
        }
    }
}

node* lst(){
    for(int i=0;i<V;++i) arry[i]=NULL;
    for(int i=0;i<V;++i){
        cout<<"How many Edges connected to "<<i<<" th node ";
        int n;cin>>n;
        for(int j=0;j<n;++j){
            cout<<"enter edge (X->Y) "<<j<<"-> ";
            node* nn = new node;
            cin>>nn->data;
            nn->next=NULL;
            if(arry[i]==NULL){
                arry[i]=nn;
            }else{
               nn->next=arry[i];
               arry[i]->next=NULL;
               arry[i]=nn; 
            }
        }
    }/* for(int i=0;i<V;++i){
        node* temp = arry[i];
        cout<<i<<"\n";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;

        }
        cout<<endl;} */
    Bfs();
}
int main(){
    cout<<"how many vertices ";cin>>V;
    cout<<"enter no of edges ";cin>>E;
    
    for(int i=0;i<V;++i){
        cout<<"enter vertex "<<i<<" ";
        cin>>arr[i];
    } 
    lst();
    return 0;
}