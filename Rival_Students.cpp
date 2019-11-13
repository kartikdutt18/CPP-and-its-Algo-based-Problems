//https://codeforces.com/contest/1257/problem/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,a,b;
        cin>>n>>x>>a>>b;
        if(a>b) swap(a,b);
        while(x>0 && a>1){
            a--;
            x--;
        }
        while(x>0 && b<n){
            b++;
            x--;
        }
        cout<<b-a<<endl;
    }
    return 0;
}