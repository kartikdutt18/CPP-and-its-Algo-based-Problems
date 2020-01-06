// Q 17.1
// DP
// EPI

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// O(S*N) / O(S)
ll countCombinations(ll n, vector<ll> singleScores)
{
    vector< vector<ll> > dp(singleScores.size(),1);
  

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<singleScores.size();j++)
        {
            dp[j] = (j>=1) ? dp[j] : 0;
            dp[]
        }
    }
    return dp[singleScores.size() - 1][n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> singleScore;
        singleScore.push_back(2);
        singleScore.push_back(3);
        singleScore.push_back(7);
        cout << countCombinations(n, singleScore) << endl;
    }
    return 0;
}