#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node{
    int data;
    node* next;                             //declare node ;
};
stack<int>st;                               //stack declaration for DFS;
queue<int>q;                                //queue for BFS;
node* arr[10];                              //stores nodes ;
string info[10];                            //info for gtting names; 
int visited[10];
void bfs(int x){                            //BFS function implementation using queue;
    cout<<"\nBFS traversal\n";
   visited[x]=1;
   q.push(x);
   while(!q.empty()){
       int k = q.front();q.pop();
       node* temp=arr[k];
       cout<<"parent\n"<<info[k];
       cout<<"children\n";
       while (temp!=NULL)
       {
           if(!visited[temp->data]){
            cout<<info[temp->data]<<" ";
            visited[temp->data]=1;
           }
           temp=temp->next;
       }
       
    } 
}
void dfs(int x){                            //DFS function implementation using stack;
    cout<<"\nDFS traversal\n";
    visited[x]=1;
    st.push(x);
    while(!st.empty()){
        int k = st.top();st.pop();
        node* temp = arr[k];
        cout<<"parent\n"<<info[k];
        cout<<"children\n";
        while(temp!=NULL){
            if(!visited[temp->data]){
                cout<<info[temp->data]<<" ";
                visited[temp->data]=1;
            }
            temp=temp->next;
        }
    }
}
void list(){                                    //List for creating array of nodes
    arr[1]->data=2;
    arr[1]->next->data=3;
    arr[1]->next->next->data=4;
    arr[1]->next->next->next->data=5;
    arr[1]->next->next->next->next->data=6;
    arr[2]->data=1;
    arr[3]->data=1;
    arr[3]->next->data=5;
    arr[3]->next->next->data=4;
    arr[4]->data=1;
    arr[5]->data=1;
    arr[5]->next->data=2;
    arr[6]->data=1;
    bfs(1);                                     //BFS call
    dfs(1);                                     //DFS call
}
int main(){
    info[1]="College";                         //information collection
    info[2]="Gates";
    info[3]="Hostels";
    info[4]="Canteens";
    info[5]="Grounds";
    info[6]="Stores";
    list();
    return 0;
}
