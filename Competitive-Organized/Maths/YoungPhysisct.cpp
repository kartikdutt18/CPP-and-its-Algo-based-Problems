//https://codeforces.com/problemset/problem/69/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin>>t;
    vector<vector<ll> > sums(3,vector<ll>(t,0));
    for(ll i =0;i<t;i++)
    {
        cin>>sums[0][i]>>sums[1][i]>>sums[2][i];
    }
    if (accumulate(sums[0].begin(), sums[0].end(), 0) == 0 &&
        accumulate(sums[1].begin(), sums[1].end(), 0) == 0 &&
        accumulate(sums[2].begin(), sums[2].end(), 0) == 0)
    {
            cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
        return 0;
}
