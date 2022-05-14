#include<bits/stdc++.h>
using namespace std;
class student{
    int rno;
    string name;string address;
    public:
    void getdata(){
        cout<<"enter name ";
        cin>>name;
        cout<<"enter rno ";
        cin>>rno;
        cout<<"enter addresss ";cin>>address;
    }
    void putdata(){
        cout<<endl;
        cout<<"rno\t\tname\t\taddress";
        cout<<rno<<"\t  "<<name<<"\t\t"<<address;
        cout<<endl;
    }
};
class seq_file{
    char file_name[20];
    public:
    seq_file(char f[20]){
        strcpy(file_name,f);
    }
    void create(){
        ofstream file;
        student s;
        file.open(file_name);
        s.getdata();
        file.write(reinterpret_cast<char*>(&s),sizeof(s));
        file.close();
    }
    void add(){
        ofstream file;
        student s;
        file.open(file_name,ios::app);
        file.write(reinterpret_cast<char*>(&s),sizeof(s));
        file.close();
    }
    void display(){
        ifstream file;
        student s;
        file.open(file_name);
        while(!file.eof()){
        file.read(reinterpret_cast<char*>(&s),sizeof(s));
            s.putdata();
        file.read(reinterpret_cast<char*>(&s),sizeof(s));
        }
        file.close();
    }
};
int main(){
    student s;
    char f[25];
    cin.getline(f,15);
    seq_file s1(f);
    s1.create();
    s1.display();
    return 0;
}