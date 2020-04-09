//https://codeforces.com/problemset/problem/122/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool generateLuckyNos(ll limit)
{
    queue<ll> q;
    q.push(4);
    q.push(7);
    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        if(limit % cur==0)
        {
            return true;
        }
        if((cur*10+4) <= limit)
        {
            q.push(cur*10+4);
        }
        if((cur*10+7) <= limit)
        {
            q.push(cur * 10 + 7);
        }
    }
    return false;
}
int main()
{
    ll t;
    cin>>t;
    if(generateLuckyNos(t))
    {
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
