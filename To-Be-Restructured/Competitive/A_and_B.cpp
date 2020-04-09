#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long> dp(1000000009, -1);
long long minSteps(long long a, long long b, long long step = 1)
{
    if (a == b)
        return 0;
    if (dp[abs(a - b)] != -1)
        return dp[abs(a - b)];
    long long cnt = 0;
    if (a < b && a + step <= b)
        a += step;
    else
        b += step;
    step++;
    cnt++;
    return cnt + minSteps(a, b, step);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b;
        cin >> a >> b;
        cout << minSteps(0, abs(a - b)) << endl;
    }
    return 0;
}