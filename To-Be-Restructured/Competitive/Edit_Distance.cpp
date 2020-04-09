//https://leetcode.com/problems/edit-distance/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word2.length()+2,vector<int> (word1.length()+2,0));

    
    for(int i=1;i<word2.length();i++){
        dp[i][0]=dp[i-1][0]+1;
        
    }
    for(int i=1;i<word1.length();i++){
        dp[0][i]=dp[0][i-1]+1;
    }

    
        for(int j=1;j<=word2.length();j++){
            for(int i=1;i<=word1.length();i++){
                if(word1[i-1]==word2[j-1]){
                    dp[j][i]=dp[j-1][i-1];
                }
                else{
            dp[j][i]=min(dp[j-1][i],dp[j][i-1])+1;}
          
        }
        
    }
    
    for(int j=0;j<word2.length();j++){
        for(int i=0;i<word1.length();i++){
        cout<<dp[j][i]<<" ";
        }
        cout<<endl;
    }
    

return dp[word2.length()][word1.length()];}