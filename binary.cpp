 #include<iostream>
#include<stack>
using namespace std;
struct node{
    int num;
    node* next,*prev;
};
class binary{
    private:
    node* head = NULL,*temp = NULL,*head2 = NULL,*p = NULL,*head1 = NULL,*temp1 = NULL,*head3 = NULL;
    public:
    node* create(int k){
        node* p;
        p = new node;
        p->num=k;
        p->next = NULL;
        p->prev = NULL;
        return p;
    }
    node* insert(node* m,int j){
        p = create(j);
        if(m == NULL){
            m = p;
        }
        else{
            temp = m;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = p;
            p->prev=temp;
            p->next = NULL;
        }
        return m;
    }
    void display(node *m){
        temp = m;
        while(temp != NULL){
            cout<<temp->num<<" ";
            temp = temp->next;
        }
    }
    void binaryInsert(){
        int a,t;
        cout<<"enter decimal number ";
        cin>>a;
        while(a!=0){
            t = a%2;
            head = insert(head,t);
            a = a/2;
        }
         /* cout<<"binary number is BUT it is ulta "<<endl;
        display(head); */ 
     
    }
    void comple1(){
        node* temp;
        int k = 0;
        int l = 1;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        while(temp != NULL){
            if(temp->num == 1){
                head2 = insert(head2,k);
            }
            if(temp->num == 0){
                head2 = insert(head2,l);
            }
            temp = temp->prev;
        }
        cout<<"\n1's complement of given number is :\n";
        display(head2);
    }
    void comple2(){
        stack<int>st;
        temp = head2;
        int carry;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(temp->num == 1){
            carry = 1;
        }
        if(temp->num == 0){
            carry = 0;
        }
        cout<<"\n2's complement of given no. is \n";
        while(temp!=NULL){
            if(temp->num == 1 && carry == 1){
                st.push(0);
                carry = 1;
            }
            else if(temp->num == 1 && carry == 0){
                st.push(1);
                carry = 0;
            }
            else if(temp->num == 0 && carry == 1){
                st.push(1);
                carry = 0;
            }
            else if(temp->num == 0 && carry == 0){
                carry = 0;
                st.push(0);
                carry = 0;
            }
            else{
                carry = 1;
                st.push(1);
            }
            temp = temp->prev;
            
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }

    }
    void binaryInsert1(){
        int a,t;
        cout<<"\nenter 2nd decimal number ";
        cin>>a;
        while(a!=0){
            t = a%2;
            head1 = insert(head1,t);
            a = a/2;
        }
    }
    void addBinary(){
        int o=0,z=1;
        temp = head;
        temp1 = head2;
        int carry = 0;
        temp = head;
        temp1 = head;
        if(temp->num==1 && temp1->num == 1){
            carry = 1;
        }
        while(temp->next != NULL && temp->next != NULL){
            if(temp->num == 0 && temp1->num == 0 && carry == 0){
                head3 = insert(head3,o);
                carry = 0;
            }
            if(temp->num == 0 && temp1->num == 1 && carry == 0){
                head3 = insert(head3,z);
                carry = 0;
            }
            if(temp->num == 1 && temp1->num == 0 && carry == 0){
                head3 = insert(head3,z);
                carry = 0;
            }
            if(temp->num == 1 && temp1->num == 1 && carry == 0){
                head3 = insert(head3,o);
                carry = 1;
            }
            if(temp->num == 0 && temp1->num == 1 && carry == 1){
                head3 = insert(head3,z);
                carry = 1;
            }
            if(temp->num == 1 && temp1->num == 0 && carry == 1){
                head3 = insert(head3,o);
                carry = 1;
            }
            if(temp->num == 1 && temp1->num == 1 && carry == 1){
                head3 = insert(head3,z);
                carry = 1;
            }
            if(temp->num == 0 && temp1->num == 0 && carry == 1){
                head3 = insert(head3,z);
                carry = 0;
            }
            if(carry == 1){
                head3 = insert(head3,z);
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        /* temp = head3; */
        /* display(head3); */
        temp = head3;
        while(temp->)
        cout<<"\naddition of binary number is \n";
        while(temp!=NULL){
            cout<<temp->num<<" ";
            temp = temp->prev;
        }
    }
};
int main(){
    binary b;
    b.binaryInsert();
    b.comple1();
    b.comple2();
    b.binaryInsert1();
    b.addBinary();
    return 0;
}
