//https://leetcode.com/problems/first-unique-character-in-a-string/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    map<char,pair<int,int>> ht;
    int j=0;
    for(auto i:s){
        if(ht.count(i)){
            ht[i].second=ht[i].second+1;
        }
        else{
            ht.insert(make_pair(i,make_pair(j,1)));
        }
        j++;
    }
    int ans=INT_MAX;
    for(auto i:ht){
        if(i.second.second==1){
            ans=min(ans,i.second.first);
        }
    }
    return ans;
}