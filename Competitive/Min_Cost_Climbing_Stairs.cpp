//https://leetcode.com/problems/min-cost-climbing-stairs/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        int n=cost.size();
        if(n==0) return 0;
        if(n==1) return cost[0];
        if(n==2) return min(cost[0],cost[1]);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
                dp[i]=min(dp[i-1],dp[i-2]+cost[i]);
        }
    return dp[n-1];
}