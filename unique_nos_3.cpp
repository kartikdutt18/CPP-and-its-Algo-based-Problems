#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int unique(int *a,int n){
    int sb[64]={0};
    for(int i=0;i<n;i++){
        int no=a[i];
        int j=0;
        while(no){
            sb[j]+=(no&1);
            no=no>>1;
            j++;
        }
    }
    int m=sizeof(sb)/sizeof(sb[0]);
    int i=0;
    int l=1;
    int ans=0;
    while(i!=m){
        sb[i]=sb[i]%3;
        ans+=sb[i]*l;
        l=l*2;
        i++;
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=unique(arr,n);
    cout<<res<<endl;
    return 0;
}