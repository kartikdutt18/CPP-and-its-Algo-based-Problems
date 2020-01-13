//https://codeforces.com/problemset/problem/327/A
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> kadaneAlgo(vector<ll> v)
{
    int curSum=0,maxSum=v[0];
    int start=0,end=0,s=0;
    for(int i=0;i<v.size();i++)
    {
        curSum+=v[i];
        if(curSum>maxSum)
        {
            maxSum=curSum;
            start=s;
            end=i;
        }
        if(curSum<0)
        {
            curSum=0;
            s=i+1;
        }
    }
    return make_pair(start,end);
}
void flippingGame(vector <ll> v)
{
    vector<ll> dp;
    for(auto i:v)
        dp.push_back(i==1?-1:1);
    pair<int,int> p = kadaneAlgo(dp);
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans+= (v[i])*(i<p.first || i>p.second);
        ans+= (1-v[i])*(i>=p.first && i<=p.second);
    }
    cout<<ans<<endl;
    return;
};

int main()
{
    int n;
    cin>>n;
    vector <ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    return 0;
}