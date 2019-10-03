//https://leetcode.com/problems/generate-parentheses/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*vector<string> generateParenthesis(int n)
{
    if(n<=0) return {};
    vector<vector<string>> dp(n+2);
    vector<string> temp={"()"};
    dp[1]=temp;
    for(int i=2;i<=n;i++){
        set<string> s;
        for(auto j:dp[i-1]){
            s.insert("("+j+")");
            s.insert("()"+j);
            s.insert(j+"()");
        }
        for(auto j:s){
            dp[i].push_back(j);
        }
    }
    return dp[n];
}
*/

set<string> ht;
void placepara(int open,int closed,int n,string s){
    if(closed==n){
        ht.insert(s);
        return;
    }
    s+='(';
    open++;
    placepara(open,closed,n,s);
    
    if(open>closed){
        s+=')';
        closed++;
        placepara(open, closed, n, s);
    }
    open--;
    s.pop_back();
    if(closed>open && s.back()==')'){
        s.pop_back();
        closed--;
    }
}
vector<string> generateParenthesis(int n){

}