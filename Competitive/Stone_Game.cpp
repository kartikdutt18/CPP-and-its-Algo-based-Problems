//https://leetcode.com/problems/stone-game/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector <vector<pair<int,int>>> dp(500,vector<pair<int,int>>(500,pair(-1,-1)));

int GetScore(vector<int> stones,int n){
            for(int i=0;i<n;i++){
                dp[i][i]=pair(stones[i],0);
            }
            for(int k=2;k<=n;k++){
                for(int i =0;i<=n-k;i++){
                    int j = i + k -1;
                    if(dp[i+1][j].second+stones[i]>dp[i][j-1].second+stones[i]){
                        dp[i][j]=pair(dp[i+1][j].second+stones[i],dp[i+1][j].first);
                    }
                    else{
                        dp[i][j]=pair(dp[i][j-1].second+stones[i],dp[i][j-1].first);
                    }
                }
            }
        return dp[0][n-1].first,dp[0][n-1].second;
}


bool stoneGame(vector<int>& piles) {
        GetScore(piles,piles.size());
        int n=piles.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<" <"<<dp[i][j].first<<","<<dp[i][j].second<<">  ,";
            }
            cout<<endl;
        }
        return true;


            
    }