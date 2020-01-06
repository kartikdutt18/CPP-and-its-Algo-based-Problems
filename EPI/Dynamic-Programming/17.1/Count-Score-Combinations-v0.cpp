// Q 17.1
// DP
// EPI

#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// O(S*N) / O(S*N)
ll countCombinations(ll n,vector<ll> singleScores)
{
    vector< vector<ll> > dp(singleScores.size(),vector<ll> (n+1,0));
    for(int i=0;i<singleScores.size();i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=i>=1?dp[i-1][j]:0;
            dp[i][j] += (j - singleScores[i]) >= 0 ? dp[i][j - singleScores[i]] : 0;
           
        }
    }
    return dp[singleScores.size()-1][n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> singleScore;
        singleScore.push_back(2);
        singleScore.push_back(3);
        singleScore.push_back(7);
        cout<<countCombinations(n,singleScore)<<endl;
    }
    return 0;
}