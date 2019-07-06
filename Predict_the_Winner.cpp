//https://leetcode.com/problems/predict-the-winner/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool GetScore(vector<int>nums){
    vector<vector<pair<int,int>>> score(nums.size()+1,vector<pair<int,int>>(nums.size()+1,make_pair(0,0)));
    int ts=0;
    for(int i=0;i<nums.size();i++){
        score[i][i]=pair(nums[i],0);
        ts+=nums[i];
    }
    int n=nums.size();
    for(int k=2;k<=n;k++){
        for(int i=0;i<=n-k;i++){
            int j=i+k-1;
            if(score[i][j-1].second+nums[j]>score[i+1][j].second+nums[i]){
                score[i][j].first=score[i][j-1].second+nums[j];
                score[i][j].second=score[i][j-1].first;
            }
            else{
                score[i][j].first=score[i+1][j].second+nums[i];
                score[i][j].second=score[i+1][j].first;
            }
        }
    }
 return  score[0][n-1].first>=score[0][n-1].second;}

bool PredictTheWinner(vector<int>& nums) {
    if(nums.size()%2==0) return true;
    return GetScore(nums);
}