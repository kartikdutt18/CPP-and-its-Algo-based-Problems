//https://leetcode.com/problems/jewels-and-stones/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map <char,int> ht;
        for(auto i: J){
            ht.insert(make_pair(i,0));
        }
        for(auto i: S){
            if(ht.count(i)){
                ht[i]=ht[i]+1;
            }
        
        }
        int ans=0;
        for(auto i: ht){
            ans+=i.second;
        }
   return ans; }
};