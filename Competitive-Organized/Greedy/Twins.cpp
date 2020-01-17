//https://codeforces.com/problemset/problem/160/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] += v[i] + ((i > 0) ? dp[i - 1] : 0);
    }
    int curSum = 0;
    int ans = n;
    for (int j = n - 1; j > 0; j--)
    {

        curSum += v[j];
        if (curSum > dp[j - 1])
        {
            ans = n - j;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}