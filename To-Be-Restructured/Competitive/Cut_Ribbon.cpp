//https://codeforces.com/problemset/problem/189/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int GetMax(int n, vector<int> len)
{
    vector<int> dp(n + 1, 0);
    if (n < len[0])
        return 0;

    for (int i = len[0]; i <= n; i++)
    {
        int q1 = dp[i - len[0]] + (i - len[0] == 0 || dp[i - len[0]] != 0);
        int q2 = INT_MIN;
        int q3 = INT_MIN;
        if (i >= len[1])
            q2 = dp[i - len[1]] + (i - len[1] == 0 || dp[i - len[1]] != 0);
        if (i >= len[2])
            q3 = dp[i - len[2]] + (i - len[2] == 0 || dp[i - len[2]] != 0);
        dp[i] = max(q1, max(q2, q3));
    }
    return dp[n];
}
int main()
{
    int n;
    int a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    cout << GetMax(n, v);
    return 0;
}