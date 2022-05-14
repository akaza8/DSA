#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int r,int mid){
    int ar[r];
    int l_sz = mid-l+1;
    int r_sz = r-mid;
    int l_arr[l_sz+1];
    int r_arr[r_sz+1];
    for(int i=0;i<l_sz;++i){
        l_arr[i] = arr[i];
         
    }
    for(int i=0;i<r_sz;++i){
        r_arr[i] = arr[i+mid+1];
        
    }
    l_arr[l_sz] = INT_MAX;
    r_arr[r_sz] = INT_MAX;
    int l_indx =0;
    int r_indx =0;
    for(int i=l;i<r;++i){
        if(l_arr[l_indx]<r_arr[r_indx]){
            ar[i] = l_arr[l_indx];
            l_indx++;
        }else{
            ar[i] = r_arr[r_indx];
            r_indx++;
        }
    }
    for(int i : ar){
        cout<<i<<" ";
    }
}
void mergeSort(int arr[],int l,int r){
    int mid = l+r/2;
    if(l==r) return;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid,r);
    merge(arr,l,r,mid);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    mergeSort(arr,0,n);
    return 0;
}