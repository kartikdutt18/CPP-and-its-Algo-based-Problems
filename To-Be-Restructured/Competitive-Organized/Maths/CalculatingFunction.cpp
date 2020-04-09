//https://codeforces.com/problemset/problem/486/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void calcFunction(ll x)
{
    ll ans = (x & 1 ? -1 : 1) * ceil(x / 2.0);
    cout<<ans<<endl;
}
int main()
{
    ll t;
    cin>>t;
    calcFunction(t);
    return 0;

}