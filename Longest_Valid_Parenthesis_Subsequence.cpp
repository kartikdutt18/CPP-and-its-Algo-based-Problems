#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s)
{
    vector<int> opening(s.length()+1,0);
    vector<int> ans(s.length()+1,0);
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            opening[i+1]=opening[i]+1;
            ans[i+1]=ans[i];
        }
        else if(s[i]==')'){
            if(opening[i]>ans[i]){
                ans[i+1]+=1;
            }
            opening[i + 1] = opening[i];
        }
    }
    return 2*ans.back();
}