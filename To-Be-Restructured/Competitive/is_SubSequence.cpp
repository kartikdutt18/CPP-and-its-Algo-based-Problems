//https://leetcode.com/problems/is-subsequence/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i=0,j=0;
    while(i!=s.length() && j!=t.length()){
        if(s[i]==t[j]){
            i++;
        }
        j++;
    }
    return i==s.length();
}