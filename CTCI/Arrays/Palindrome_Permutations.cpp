//CTCI 1.4
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    vector<int> freq(26,0);
    for(auto i:s) freq[i-'a']++;
    int cnt_odd=0;
    for(auto i:freq)cnt_odd+=i&1;
    return cnt_odd<2;
}