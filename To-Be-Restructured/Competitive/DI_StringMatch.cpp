//https://leetcode.com/problems/di-string-match/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> diStringMatch(string S)
{
    int i=0;
    int j=S.size();
    vector<int> v;
    int index=0;
    while(i<=j){
        if(S[index]=='I'){
            v.push_back(i);
            i++;
        }
        else{
            v.push_back(j);
            j--;
        }
        index++;
    }
return v;}