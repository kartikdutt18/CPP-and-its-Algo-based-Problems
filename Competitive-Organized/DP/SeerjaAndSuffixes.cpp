//https://codeforces.com/problemset/problem/368/B
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> dp(1000000,0);
void fillDP(vector<ll> arr)
{
    set <ll> ht;
    for(int i=arr.size()-1;i>=0;i--)
    {
        ht.insert(arr[i]);
        dp[i]=ht.size();
    }
    return;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    fillDP(arr);
    for(int i=0;i<m;i++)
    {
        int query;
        cin>>query;
        cout<<dp[query-1]<<endl;
    }
    return 0;
}