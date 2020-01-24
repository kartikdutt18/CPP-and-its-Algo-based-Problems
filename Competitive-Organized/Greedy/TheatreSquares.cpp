//https://codeforces.com/problemset/problem/1/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,m,a;
    cin>>n>>m>>a;
    n=n/a + (n%a!=0);
    m=m/a + (m%a!=0);
    cout<<n*m<<endl;
    return 0;
}