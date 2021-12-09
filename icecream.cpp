#include<iostream>
using namespace std;
struct node{
    int rno;
    node* next;
};
class student{
    node* head1=NULL,*head=NULL,*head2=NULL,*temp=NULL,*temp2=NULL,*temp1=NULL,*tempi=NULL,*tempd,*p=NULL,*head3,*head4;
    int a,v,b;
    public:
    node* create(){
        node *p = new node;
        cout<<"enter rno :";
        cin>>p->rno;
        p->next=NULL;
        return p;
    }
    node* insert(node* h){
        node* p = create();
        if(h==NULL){
            h = p;
        }
        else{
            tempi = h;
            while(tempi->next != NULL){
                tempi = tempi->next;
            }
            tempi->next=p;
        }
        return h;
    }
    void display(node* m){
        tempd = m;
        while(tempd!=NULL){
            cout<<tempd->rno<<" ";
            tempd=tempd->next;
        }
    }
    void allStud(){
        cout<<"how many students in class \n";
        cin>>a;
        for(int i=0;i<a;i++){
            head=insert(head);
        }
        cout<<"students \n";
        display(head);

    }
    void vanilla(){
        cout<<"\nenter no. of students who likes venella : ";
        cin>>v;
        for(int i=0;i<v;i++){
            head1=insert(head1);
        }
    }
    void butter(){
        cout<<"\nenter no of students who likes butterscotch : ";
        cin>>b;
        for(int i=0;i<b;i++){
            head2=insert(head2);
        }
    }
    void vorb(){
        cout<<"\nstudents who likes vanella or butterscotch : \n";
        temp1 = head1;
        temp2 = head2;
        while(temp1!=NULL){
            cout<<temp->rno<<" ";
            temp = temp->next;
        }
        temp1=head1;
        while(temp1!=NULL){
            while(temp2!=NULL){
                if(temp2->rno == temp1->rno){
                    temp2 = temp2->next;
                }
                else{
                    cout<<temp2->rno<<" ";
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
    void vandb(){
        cout<<"\nstudents who likes vanila and butterscotch : \n";
        temp = head;
        temp1 = head1;
        temp2 = head2;
            while(temp1!=NULL){
                while(temp2!=NULL){
                    if(temp1->rno == temp2->rno){
                        cout<<temp1->rno<<" ";
                    }
                    temp2=temp2->next;
                }
                temp1=temp1->next;
            }
    }
    void vnorb(){
        cout<<"\nstudents not like both:\n";
        temp = head;
        temp1 = head1;
        temp2 = head2;
        while(temp!=NULL){
            while(temp1!=NULL){
                while(temp2!=NULL){
                    if(temp->rno!=temp1->rno || temp->rno!=temp2->rno){
                        cout<<temp->rno<<" ";
                    }
                    temp2 = temp2->next;
                }
               temp1 = temp1->next; 
            }
            temp = temp->next;   
        }
    }
};
int main(){
    int z,ch;
    student s;
    s.allStud();
    s.butter();
    s.vanilla();    
    s.vandb();
    s.vnorb();
    s.vorb();  
    return 0;
}
