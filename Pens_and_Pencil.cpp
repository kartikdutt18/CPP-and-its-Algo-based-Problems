//https://codeforces.com/contest/1244/problem/0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,k,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        int n_pens=a/c+(a%c!=0);
        int n_pencil=b/d+(b%d!=0);
        if(n_pens+n_pencil<=k) cout<<n_pens<<" "<<n_pencil<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}