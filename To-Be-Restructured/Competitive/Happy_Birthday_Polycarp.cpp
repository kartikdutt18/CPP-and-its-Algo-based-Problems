//https://codeforces.com/contest/1277/problem/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


long long count_beautiful(long n)
{
    long long count = 0;
    for (int i = 1; i <= 9; i++)
    {
        long long ans = i;
        while (ans <= n)
        {
            count++;
            ans = ans * 10 + i;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << count_beautiful(n) << endl;
    }
    return 0;
}