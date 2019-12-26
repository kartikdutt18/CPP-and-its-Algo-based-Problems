//https://leetcode.com/problems/validate-stack-sequences/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
    stack<int> s;
    int j=0;
    if(pushed.size()==0) return true;
    s.push(pushed[0]);
    
    for(int i=1;i<pushed.size();i++){
        if(s.empty()) s.push(pushed[i]);
        while(s.empty()==false and s.top()==popped[j]){
            j++;
            s.pop();
        }
        s.push(pushed[i]);
    }
    while(s.empty()==false and s.top()==popped[j]){
            j++;
            s.pop();}
return s.empty();}