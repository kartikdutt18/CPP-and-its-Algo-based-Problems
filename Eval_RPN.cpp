//https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
       set<string> s={"+", "-", "*", "/"};
        stack<int> stk;
        for(auto i:tokens){
            if(!s.count(i)){
                stk.push(stoi(i));
            }
            else{
                int t1=stk.top();
                stk.pop();
                int t2=stk.top();
                stk.pop();
                if(i=="+") stk.push(t1+t2);
                else if(i=="-") stk.push(t2-t1);
                else if(i=="/") stk.push(t2/t1);
                else stk.push(t1*t2);
            }
        }
return stk.top();}