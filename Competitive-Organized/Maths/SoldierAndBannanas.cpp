//https://codeforces.com/problemset/problem/546/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll w, n ,k;
    cin>>k>>n>>w;
    ll ans = (k*(w*(w+1)/2))-n;
    ans=(ans>=0)?ans:0;
    cout<<ans<<endl;
    return 0;
}