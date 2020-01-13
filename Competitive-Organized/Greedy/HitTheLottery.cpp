//https://codeforces.com/problemset/problem/996/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void devideAndMod(int &n,int d,int &sum)
{
    sum+=n/d;
    n=n%d;
    return;
}
int main()
{
    int n;
    int ans=0;
    cin>>n;
    devideAndMod(n, 100, ans);
    devideAndMod(n, 20, ans);
    devideAndMod(n, 10, ans);
    devideAndMod(n, 5, ans);
    devideAndMod(n, 1, ans);
    cout<<ans<<endl;
    return 0;
}