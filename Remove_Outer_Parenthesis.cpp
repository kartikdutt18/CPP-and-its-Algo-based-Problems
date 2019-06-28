//https://leetcode.com/problems/remove-outermost-parentheses/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string S) {
        stack <char> s;
        string ans="";
        for(int i=0;i<S.length();i++){
            if(S[i]=='('){
                s.push('(');
                if(s.size()!=1){
                    ans+="(";
                }
            }
            else if(S[i]==')'){
                if(s.size()!=1){
                    ans+=")";
                    
                }
                s.pop();
            }
        
}
return ans;
}