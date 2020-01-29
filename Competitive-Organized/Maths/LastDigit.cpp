//https://www.spoj.com/problems/LASTDIG/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll raisePower(ll num, ll n, ll mod)
{
    num %= mod;
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * num % mod;
        num = num * num % mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, n;
        cin >> a >> n;
        cout << raisePower(a, n, 10) << endl;
    }
    return 0;
}