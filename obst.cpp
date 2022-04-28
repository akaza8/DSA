#include<bits/stdc++.h>
using namespace std;
#define N 20
int r[N][N];
class tree{
    public:
    int n;
    int p[N];
    int q[N];
    int w[N][N];
    int c[N][N];

    void getdata();
    void obst(); 
    int min(int i,int j); 
    void disp(int ,int );
};

void tree :: getdata(){
    cout<<"enter no of nodes ";
    cin>>n;
    cout<<"enter probability of successfull search ";
    for(int i=1;i<=n;++i){
        cin>>p[i];
    }
    cout<<"enter probability of unseccessfull search ";
    for(int i=0;i<=n;++i){
        cin>>q[i];
    }
}
int tree :: min(int i,int j){
    int m = 1000;
    int a;
    for(int k = i+1;k<=j;++k){
        c[i][j] = c[i][k-1]+c[k][j];
        if(c[i][j]<m) {
            m = c[i][j];
            a = k;
        }
    }
    return a;
}
void tree :: obst(){
    // for diff |j-i| = 0
    for(int i=0;i<=n;++i){
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }
    // for diff |j-i| = 1
    for(int i=0;i<=n;++i){
        w[i][i+1] = w[i][i]+p[i+1]+q[i+1];
        r[i][i+1] = i+1;
        c[i][i+1] = c[i][i]+c[i][i+1];
    }
    // for diff |j-i|>= 2
    for(int i=0;i<=n;++i){
        for(int j = 0;j<=n;++j){
            if((j-i)>=2){
                w[i][j] = w[i][j-1]+p[j]+q[j];
                int k = min(i,j);
                c[i][j] = c[i][k-1]+c[k][j]+w[i][j];
                r[i][j] = k;
            }
        }
    }
    disp(0,n);
}
void tree :: disp(int i, int j){
    int k = r[i][j];
    if(r[i][j]==0) return;
    cout<< r[i][j]<<" ";
    disp(i,k-1);
    disp(k,j);
}
 
 
int main(){
    tree ob;
    ob.getdata();
    ob.obst();
    return 0;
}