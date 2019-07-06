//https://leetcode.com/problems/ugly-number-ii/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> dp(n+3,0);
    dp[0]=1;
    int next_2=2;
    int next_3=3;
    int next_5=5;
    int i2=0,i3=0,i5=0;
    int next_mult=1;
    for(int i=1;i<n;i++){
        next_mult=min(next_2,min(next_3,next_5));
        dp[i]=next_mult;
        if(next_mult==next_2){
            next_2=2*dp[i2+1];
            i2++;
        }
        if(next_mult==next_3){
            next_3=3*dp[i3+1];
            i3++;
        }
        if(next_mult==next_5){
            next_5=5*dp[i5+1];
            i5++;
        }



    }        
return dp[n-1];}