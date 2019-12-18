//https://codeforces.com/contest/1266/problem/B
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long tc;
        cin >> tc;
        long long int temp = tc / 14 - 1 * (tc > 14);
        tc = tc - temp * 14;
        if (tc >= 15 && tc <= 20)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO \n";
    }
    return 0;
}