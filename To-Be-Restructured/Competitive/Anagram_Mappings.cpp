//https://leetcode.com/problems/find-anagram-mappings/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> anagramMappings(vector<int> &A, vector<int> &B)
{
    map<int,int> ht;
    for(int i=0;i<B.size();i++){
        ht[B[i]]=i;
    }
    vector<int> ans;
    for(auto i:A){
        ans.push_back(ht[i]);
    }
    return ans;
}