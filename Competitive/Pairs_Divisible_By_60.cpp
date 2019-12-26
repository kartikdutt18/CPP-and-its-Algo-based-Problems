//https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int numPairsDivisibleBy60(vector<int> &time)
{
    map<int,int> ht;
    for(auto i:time){
        ht[i%60]+=1;
    }
    int ans=0;
    for(auto i: ht){
        if(i.first==0) ans+=i.second;
        if(ht.count(60-i.first)){
            if(ht[60-i.first]){
                ans+=min(ht[60-i.first],ht[i.first]);
                ht[i.first] -= min(ht[60 - i.first], ht[i.first]);
                ht[60 - i.first] -= min(ht[60 - i.first], ht[i.first]);
            }
        }
    }

return ans;}