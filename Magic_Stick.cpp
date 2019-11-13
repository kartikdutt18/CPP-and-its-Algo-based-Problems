//https://codeforces.com/contest/1257/problem/B
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        int prev_x=x;
        while(x<y && x>1){
            if (x & 1 == 1 && x < y && x > 1)
                x--;
            else
                x=x*3/2;
            if(prev_x==x) break;
        }
        if(x>=y) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}