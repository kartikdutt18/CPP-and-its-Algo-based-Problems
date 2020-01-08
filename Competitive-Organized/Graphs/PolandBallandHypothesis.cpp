//https://codeforces.com/problemset/problem/755/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n+2<=1000)
    {
        cout<<n+2<<endl;
    }
    else
    {
        cout<<n-2<<endl;
    }
    return 0;
}