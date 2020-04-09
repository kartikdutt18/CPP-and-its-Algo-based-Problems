//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll raisePower(ll num, ll n, ll mod)
{
    num%=mod;
    ll res=1;
    while(n>0)
    {
        if(n&1)
            res=res*num % mod;
        num=num * num % mod;
        n>>=1;
    }
    return res;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,n,m;
        cin>>a>>n>>m;
        cout<<raisePower(a,n,m)<<endl;
    }
    return 0;
}