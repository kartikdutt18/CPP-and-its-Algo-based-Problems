//https://codeforces.com/problemset/problem/580/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_len(vector<long long > v){
    int ans=1;
    vector<int> dp(v.size(),1);
    for(int i=0;i<v.size();i++){
        if(v[i]>=v[i-1]) dp[i]=dp[i-1]+1; 
    }
    
    return dp[max_element(dp.begin(),dp.end())-dp.begin()];
}
int main(){
    int n;
    cin>>n;
    vector<long long > stocks(n);
    for(int i=0;i<n;i++) cin>>stocks[i];
    cout<<max_len(stocks)<<endl;
    return 0;
}
