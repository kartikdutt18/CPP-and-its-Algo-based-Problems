//https://leetcode.com/problems/coin-change/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount+1,-1);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        int q1=INT_MAX;
        for(auto j: coins){
            if(i>=j && dp[i-j]!=-1) q1=min(1+dp[i-j],q1); 
        }
        if(q1!=INT_MAX) dp[i]=q1;
    }
    return dp[amount];
}