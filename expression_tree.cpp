#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
    node(char data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class stk{
    public:
    int top = -1;
    node* arr[30];
    void push(node* data){
        if(top==29) return;
        top++;
        arr[top]= data;
    }
    node* pop(){
        if(top==-1) return NULL;
        node* t = arr[top];
        top--;
        return t;
    }
    bool isempty(){
        return top == -1;
    }
};
class tree{
    public:
    node* convert(char *ptr,int len){
        stk st;
        node* last;
        while(len--){
        node* nn = new node(*ptr);
        if(isalpha(*ptr)) {st.push(nn) ;ptr-=1;}
        else{
            node* t1 = st.pop();
            node* t2 = st.pop();
            nn->left = t1;
            nn->right = t2;
            st.push(nn);
            ptr-=1;
        } }
        last = st.pop();
    }
    void disspost(node* root){
        stk s1,s2;
        if(root!=NULL) s1.push(root);
        while(!s1.isempty()){
            node* t = s1.pop();
            if(t->left) s1.push(t->left);
            if(t->right) s1.push(t->right);
            s2.push(t);
            
        }
        while(!s2.isempty()){
            cout<<(s2.pop())->data;
        }
    }
};

int main(){
    char exp[30];
    cin>>exp;
    int len = strlen(exp);
    tree T;
    node* root = T.convert(&exp[len-1],len);
    T.disspost(root);
    return 0;
}