//https://leetcode.com/problems/daily-temperatures/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int>ans(T.size(),0);
    stack<pair<int,int>> s;
    for(int i=0;i<T.size();i++){
        if(s.empty()) s.push(pair(i,T[i]));
        while(s.empty()==false and s.top().second<T[i]){
            ans[s.top().first]=i-s.top().first;
            s.pop();
        }
        s.push(make_pair(i,T[i]));

    }
   return ans;         
}