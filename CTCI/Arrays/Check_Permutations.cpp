//CTCI 1.2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(string s1,string s2){
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    for(auto i:s1) v1[i-'a']++;
    for(auto i:s2) v2[i-'a']++;
    return v1==v2;
}