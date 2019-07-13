//https://leetcode.com/problems/divisor-game/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool divisorGame(int N)
{
    return !(N & 1);
}
bool divisorGame1(int N){
    vector<bool> dp(N+1,false);
    dp[0]=true;
    dp[2]=true;
    for(int i=3;i<=N;i++){
        for(int j=i/2;j>=0;j--){
            if(j%i==0 && (i-j)%2==0 && dp[j]==true){
                true;
            }
        }
    }
return dp[N];}
