//https://leetcode.com/problems/palindrome-partitioning/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int e){
    while(i<=e){
        if(s[i]!=s[e]) return false;
        i++;
        e--;
    }
    return true;
}
vector<vector<string>> ans;
bool Generate(string s, int i, int e,vector<string> temp)
{
    if(i==s.size()){
        ans.push_back(temp);
        return false;
    }
    for(int itr=i;itr<s.length();itr++){
        if(isPalindrome(s,i,itr)){
            string t=s.substr(i,itr-i+1);
            temp.push_back(t);
            Generate(s,itr+1,e,temp);
            temp.pop_back();
        }

    }
return false;}
vector<vector<string>> partition(string s)
{
    Generate(s,0,s.size(),{});
    return ans;
}