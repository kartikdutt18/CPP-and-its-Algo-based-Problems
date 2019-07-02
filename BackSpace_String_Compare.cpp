//https://leetcode.com/problems/backspace-string-compare/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool backspaceCompare(string S, string T) {
        stack<char> s,t;
        for(auto i:S){
            if(i=='#' and not s.empty()) s.pop();
            else s.push(i);
        }
        for(auto i:T){
            if(i=='#' and not t.empty()) t.pop();
            else t.push(i);
        }
        while(not s.empty() and not t.empty()){
            if(s.top()!=t.top())
                return false;
            s.pop();
            t.pop();
        }
        return s.empty()&&t.empty();
}