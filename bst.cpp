#include<bits/stdc++.h>
using namespace std;
struct node{
    string data;
    node* next;
    node* right;
    node(string data){
        this->data = data;
        next = NULL;
        right = NULL;
    }
}* root=NULL,*temp;
node* pre;
void bst(string key){
    node* nn = new node(key);
    if(root == NULL) {
        root = nn;
        return;
    }
    while (temp!=NULL)
    {
        if(temp->data > key){
            pre = temp;
            temp = temp->next;
        }
        else{
            pre = temp;
            temp = temp->right;
        }
    }
    if(pre->data > key){
        pre->right = nn;
    }else{
        pre->next = nn;
    }
}
void inorder(node* r){
    if(r == NULL) return;
    inorder(r->next);
    cout<<r->data<<" ";
    inorder(r->right);
}
int main(){
     bst("ab");
     bst("ac");
     bst("aa");
     bst("nn");
     inorder(root);
    return 0;
}