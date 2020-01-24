//https://codeforces.com/problemset/problem/617/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void divide(ll &num,ll divisor,ll &ans)
{
    ans+=(num)/divisor;
    num=num%divisor;
}
int main()
{
    ll t;
    cin>>t;
    ll ans=0;
    for(ll i=5;i>0;i--)
    {
        divide(t,i,ans);
    }
    cout<<ans<<endl;
    return 0;
}
