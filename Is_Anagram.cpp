//https://leetcode.com/problems/valid-anagram/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    vector<int> v(26,0);
    for(auto i:s){
        v[i-'a']=v[i-'a']+1;
    }
    for(auto i:t){
        v[i-'a']=v[i-'a']-1;
    }

    for(auto i:v){
        if(i){
            return false;
        }}
    return true;
}