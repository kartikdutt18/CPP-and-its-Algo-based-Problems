//https://codeforces.com/problemset/problem/894/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countQAQ(string s)
{
    int ans = 0;
    vector<int> dp(s.length(), 0);
    for (int i = 0; i < s.length(); i++)
    {
        dp[i] = (s[i] == 'Q') + ((i > 0) ? dp[i - 1] : 0);
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            //cout<<i<<" "<<dp[i]<<" "<<dp.back()<<endl;
            ans += dp[i] * (dp.back() - dp[i]);
        }
    }
    return ans;
}
int main()
{
    string s;
    while (s.length() == 0)
        getline(cin, s);
    cout << countQAQ(s) << endl;
    return 0;
}