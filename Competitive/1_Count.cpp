//1 Count -> HackerBlocks
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void max_count(int n,int k,vector<int> arr){
    vector<vector<int> > dp(k+1,vector<int>(n+1,0));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(arr[j-1]==0) dp[i][j]=dp[i-1][j-1]+(i!=1);
            else dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    cout<<dp[k][n]<<endl;
    
}
int main(){
    return 0;
}