//https://codeforces.com/problemset/problem/327/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void flippingGame(vector <ll> v)
{
    vector<ll> dp;
    for(auto i:v)
        dp.push_back(i==1?-1:1);
    
};

int main()
{
    int n;
    cin>>n;
    vector <ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    return 0;
}