#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
    node(char dta){
        data= dta;
        left = NULL;
        right = NULL; 
    }
}* root=NULL;
char ch[20];
void display(node* root){
    if(root!=NULL){
    display(root->left);
    cout<<root->data<<" ";
    display(root->left);
    }

}
node* convert(node* root,char ptr){
    if(isalpha(ptr)) return new node(ptr);
    if(root == NULL){
        node* nn = new node(ptr);
        root = nn;
    }
    root->left= convert(root->left,ptr++);
    root->right= convert(root->right,ptr++);
    return root;
}
int main(){
    cout<<"exp ";
    cin>>ch;
    convert(root,ch[20]);
    // node*k ;
    // k = convert(root,st[0]);
    display(root);
    return 0;
}