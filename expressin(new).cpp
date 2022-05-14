#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
    node(char c){
        data = c;
        left = right= NULL;
    }
};
class stk{
    public:
    node* arr[30];int top=-1;
    int empty(){
        if(top==-1) return 1;
        return 0;
    }
    void push(node* root){
        if(top==29) return;
        else{
            top++;
            arr[top]=root;
        } 
    }
    node* pop(){
        if(!empty()){
            node* t = arr[top];
            top--;
            return t;
        }
    }
};
class tree{
    public:
    node* last;
    void convert(string st);
    void display(node* root);
    void del(node* root);
};
void tree :: convert(string st){
    stk s;
    int len = st.length();
    for(int i=len-1;i>=0;--i){
        node* nn = new node(st[i]);
        if(isalpha(st[i])){
           s.push(nn); 
        }else{
            node* t1,* t2;
            t1 = s.pop();t2=s.pop();
            nn->left= t1;
            nn->right= t2;
            s.push(nn);
        }
    }
    last = s.pop();
}
void tree :: display(node* root){
    if(root!=NULL){
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}
int main(){
    string st;
    cout<<"enter prefix ";
    cin>>st;
    tree T;
    T.convert(st);
    T.display(T.last);
    return 0;
}