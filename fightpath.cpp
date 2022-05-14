#include<iostream>
using namespace std;
int flight[15][15];
string arr[15];
int main(){
    cout<<"how many airports are there ";int v;cin>>v;
    for(int i=1;i<=v;++i){
        cout<<"enter name of airport "<<i<<" ";cin>>arr[i];
    }cout<<endl;
    for(int i=1;i<=v;++i){
        for(int j=1;j<=v;++j){
            if(i!=j&&flight[i][j]==0){
            cout<<"is there any flight in between airport "<<arr[i]<<" "<<"-> "<<arr[j]<<"\n1->Y\t0->N\t";
            int x ;cin>>x;
            if(x==1){
                cout<<"how much time required for traveling(eg. x) ";
                cin>>flight[i][j];cout<<endl;
                flight[j][i]=flight[i][j];
            }}
        }
    }
    cout<<endl<<endl;
    cout<<"Airport(souce)\t\t\tAirport(destination)\t\t\tTime";cout<<endl;
    for(int i=1;i<=v;++i){
        for(int j=1;j<=v;++j){
            if(flight[i][j]>0){
                cout<<arr[i]<<"\t\t\t"<<arr[j]<<"\t\t\t\t"<<flight[i][j];
            }cout<<endl;
        }
    }
    int flag;
    for(int i=1;i<=v;++i){
        for(int j=1;j<=v;++j){
            if(i!=j){
            if(flight[i][j]>0) flag =1 ;
            else flag =0;}
        }
    }
    if(flag==1){
        cout<<"\nAll flight paths are interconnected in graph ";
    }else
    cout<<"\nNot all flight paths are interconnected ";
    return 0;
}
/* 
                        OUTPUT
_______________________________________________________________________                      
how many airports are there 3
enter name of airport 1 delhi_airport
enter name of airport 2 mumbai_airport
enter name of airport 3 pune_airport
_______________________________________________________________________
is there any flight in between airport delhi_airport -> mumbai_airport
1->Y    0->N    1
how much time required for traveling(eg. x) 12

is there any flight in between airport delhi_airport -> pune_airport
1->Y    0->N    1
how much time required for traveling(eg. x) 11

is there any flight in between airport mumbai_airport -> pune_airport
1->Y    0->N    1
how much time required for traveling(eg. x) 5

____________________________________________________________________________

Airport(souce)                  Airport(destination)                    Time
-----------------------------------------------------------------------------
delhi_airport                   mumbai_airport                          12
delhi_airport                   pune_airport                            11
mumbai_airport                  delhi_airport                           12

mumbai_airport                  pune_airport                            5
pune_airport                    delhi_airport                           11
pune_airport                    mumbai_airport                          5
 
*/