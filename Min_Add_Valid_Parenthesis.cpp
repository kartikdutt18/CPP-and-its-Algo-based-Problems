//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string S) {
    stack <char> s;
    int cnt=0;
    for(auto i: S){
        if(i=='('){ s.push(i);}
        else if(s.size()>=1 && i==')') s.pop();
        else cnt++;
        
    }        
return s.size()+cnt;}
//Without Stack
int minAddToMakeValid2(string S) {
        int bal=0;
        int ans=0;
        for(auto i: S){
            if(i=='('){ bal++;}
            else if(i==')') bal--;
            if(bal==-1){
                ans+=1;
                bal+=1;
            }
        }        
    return ans+bal;}
