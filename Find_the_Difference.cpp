//https://leetcode.com/problems/find-the-difference/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t){
    vector<int> v(26,0);
    for(auto i:s){
        v[i-'a']=v[i-'a']+1;
    }
    for(auto i:t){
        v[i-'a']=v[i-'a']-1;
    }
    int j=0;
    for(auto i:v){
        if(i==-1){
            return j+'a';
        }
    j++;}
    return 'a';
}