//https://codeforces.com/contest/479/problem/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int ans = a + b + c;
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * (b + c));
    ans = max(ans, a * b * c);

    cout << ans << endl;
    return 0;
}