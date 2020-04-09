//https://codeforces.com/problemset/problem/337/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for (int i = n - 1; i < m; i++)
    {
        ans = min(ans, v[i] - v[i - n + 1]);
    }
    cout << ans << endl;
    return 0;
}