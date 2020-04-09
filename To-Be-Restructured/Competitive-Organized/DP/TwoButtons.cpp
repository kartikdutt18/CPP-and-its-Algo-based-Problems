//https://codeforces.com/problemset/problem/520/B
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll convert(ll n,ll m)
{
    ll countOperations=0;
    while(m!=n)
    {
        if(n<m && m%2==0)
        {
            m/=2;
        }
        else
        {
            m++;
        }
        countOperations++;
    }
    return countOperations;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<convert(n,m)<<endl;
    return 0;
}