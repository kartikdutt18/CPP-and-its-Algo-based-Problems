//https://codeforces.com/problemset/problem/318/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printOddEven(ll end,ll k)
{
    if (k <= (end + 1) / 2)
        cout<<2*(k-1)+1<<endl;
    else
        cout << (k - (end + 1) / 2) * 2 << endl;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    printOddEven(n,k);
    return 0;
}