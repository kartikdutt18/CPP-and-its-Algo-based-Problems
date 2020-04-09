//Ch8 Problem-> 1 in CTCI 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int triple_step(int n){
    int a,b,c;
    a=1;
    b=1;
    c=2;
    int ans=c;
    for(int i=2;i<n;i++){
        ans=c+a+b;
        a=b;
        b=c;
        c=ans;

    }
return ans;}

int main(){
    for(int i=3;i<10;i++)
        cout<<triple_step(i)<<endl;
return 0;}