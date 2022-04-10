#include<bits/stdc++.h>
using namespace std;
struct node{
    string key;
    string value;
    node* left;
    node* right;
    node(string key,string value){
        this->key = key;
        this->value = value;
        left = NULL;
        right= NULL;
    }
};
class dict{
    public:
    node* root = NULL;
    void create(){
        char ans;
        do{
        cout<<"enter key and value ";
        string k,v;
        cin>>k>>v;
        node* nn = new node(k,v);
        if(root==NULL){
            root = new node(k,v);
        }
        else{
        insert(root,nn);}
        cout<<"conyinue y ";
        cin>>ans;
        }while(ans=='y');
    }
    /* void insert(node* rt,node* nn){
        if(rt->key<nn->key){
            if(rt->right==NULL){
                rt->right=nn;
            }else{
                insert(rt->right,nn);
            }}
            else{
            if(rt->left==NULL){
                rt->left=nn;
            }else{
                insert(rt->left,nn);
            }}
        
    } */
    node* insert(node* root,node* nn){
        if(root == NULL){
            return nn;
        }
        if(root->key<nn->key){
            root->right=insert(root->right,nn);
        }else{
            root->left = insert(root->left,nn);
        }

    }
    void printAscending(node* root){
        if(root == NULL){
            return;
        }
        printAscending(root->left);
        cout<<root->key<<" -> "<<root->value<<endl;
        printAscending(root->right);
    }
    void printDesending(node* root){
        if(root == NULL) return;
        printDesending(root->right);
        cout<<root->key<<" -> "<<root->value<<endl;
        printDesending(root->left);
    }
    int searchUC(node* root,string key,string update,int cnt){
        if(root->key==key){
            root->value = update;
            return cnt;
        } 
        else if(root->key < key) searchUC(root->right,key,update,cnt++);
        else if(root->key >= key) searchUC(root->left,key,update,cnt++);
        else {cout<<"key not found ";return 0;}
    }
    node* deleteNode(node* root,string key){
        if(root == NULL) return root;
        if(root->key<key){
            root->right = deleteNode(root->right,key);
        }
        if(root->key>key){
            root->left = deleteNode(root->left,key);
        }
        if(root->left==NULL && root->right == NULL){
            delete(root);
            return NULL;
        } 
        if(root->left==NULL && root->right){
            node* temp = root->right;
            delete(root);
            return temp;
        }
        if(root->right == NULL && root->left){
            node* temp = root->left;
            delete(root);
            return temp;
        }
        // special case
        node* temp = inordersuccessor(root->right);
        root->key = temp->key;
        root->left = deleteNode(root->left,temp->key);
        return root;
    }
    node* inordersuccessor(node* root){
        node* temp = root;
        while(temp && temp->left != NULL){
            temp=temp->left;
        }
        return temp;
    }

};
int main(){
    dict d;
    int ch=1; 
    node* nn;
    while(ch){
        cout<<"\nch ";
        cin>>ch; char k;string kv,v;string kv1;
        switch(ch){
            case 1:
            d.create();
            break;
            case 0:
            cout<<"done";
            // d.display(root);
            case 2:
            if(d.root){
               
                cout<<"press A for print in ascending and D for Descending ";
                cin>>k;
                if(k =='A')
                d.printAscending(d.root);
                else    d.printDesending(d.root);}
            else{
                cout<<"no value";
            }
            break;
            case 3:
            cout<<"enter key and value to be updte ";
            
            cin>>kv>>v;
            d.searchUC(d.root,kv,v,0);
            break;
            case 4:
            cout<<"key want to delete ";
            cin>>kv1;
            d.deleteNode(d.root,kv1);
            break;

        }
    }
     
    return 0;
}
