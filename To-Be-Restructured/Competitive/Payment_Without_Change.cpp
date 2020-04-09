//https://codeforces.com/contest/1256/problem/0
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
        long long a,b,n,S;
        cin>>a>>b>>n>>S;
        long long  div=S/n;
        if(div>a) div=a;
        if(div*n+b>=S) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
